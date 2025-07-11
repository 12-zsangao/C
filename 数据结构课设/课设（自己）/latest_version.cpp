#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STATIONS 50
#define MAX_ROUTES 10
#define MAX_NAME 50
#define MAX_EDGES 100
#define BUS_SPEED 0.25 // �������ٶȣ�km/min
#define WALK_SPEED 0.1 // �����ٶȣ�km/min
#define MAX_PASSWORD 20 // ������󳤶�

// վ��ṹ��
typedef struct {
    int id;
    char name[MAX_NAME];
    int is_bus_station; // 1Ϊ����վ�㣬0Ϊ�ǹ���վ��
} Station;

// ��·�ṹ��
typedef struct {
    int id;
    int station_count;
    int stations[MAX_STATIONS];
    float distances[MAX_STATIONS]; // ����վ������
} Route;

// ���б߽ṹ��
typedef struct {
    int from;
    int to;
    float distance;
} WalkEdge;

// ·���ṹ��
typedef struct {
    int path[MAX_STATIONS];
    int path_length;
    float time;
    float distance;
    int transfers;
    char modes[MAX_STATIONS][10];
} Path;

// ȫ�ֱ���
Station stations[MAX_STATIONS];
Route bus_routes[MAX_ROUTES];
WalkEdge walk_edges[MAX_EDGES];
int station_count = 0;
int route_count = 0;
int walk_edge_count = 0;
char admin_password[MAX_PASSWORD] = "admin123";
int password_set = 1;

// �������ݵ��ļ�
void save_data() {
    FILE *fp = fopen("bus_data.txt", "w");
    if (!fp) {
        printf("�ļ���ʧ�ܡ�\n");
        return;
    }
    
    fprintf(fp, "%d\n", station_count);
    for (int i = 0; i < station_count; i++) {
        fprintf(fp, "%d %s %d\n", stations[i].id, stations[i].name, stations[i].is_bus_station);
    }
    
    fprintf(fp, "%d\n", route_count);
    for (int i = 0; i < route_count; i++) {
        fprintf(fp, "%d %d", bus_routes[i].id, bus_routes[i].station_count);
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            fprintf(fp, " %d", bus_routes[i].stations[j]);
        }
        for (int j = 0; j < bus_routes[i].station_count - 1; j++) {
            fprintf(fp, " %.2f", bus_routes[i].distances[j]);
        }
        fprintf(fp, "\n");
    }
    
    fprintf(fp, "%d\n", walk_edge_count);
    for (int i = 0; i < walk_edge_count; i++) {
        fprintf(fp, "%d %d %.2f\n", walk_edges[i].from, walk_edges[i].to, walk_edges[i].distance);
    }
    
    fprintf(fp, "%d %s\n", password_set, admin_password);
    
    fclose(fp);
    printf("�����ѱ��浽�ļ���\n");
}

// ���ļ���������
void load_data() {
    FILE *fp = fopen("bus_data.txt", "r");
    if (!fp) {
        printf("�ļ���ʧ�ܣ���ʹ��Ĭ�����ݳ�ʼ����\n");
        return;
    }
    
    if (fscanf(fp, "%d", &station_count) != 1) {
        fclose(fp);
        return;
    }
    for (int i = 0; i < station_count; i++) {
        if (fscanf(fp, "%d %s %d", &stations[i].id, stations[i].name, &stations[i].is_bus_station) != 3) {
            fclose(fp);
            return;
        }
    }
    
    if (fscanf(fp, "%d", &route_count) != 1) {
        fclose(fp);
        return;
    }
    for (int i = 0; i < route_count; i++) {
        if (fscanf(fp, "%d %d", &bus_routes[i].id, &bus_routes[i].station_count) != 2) {
            fclose(fp);
            return;
        }
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            if (fscanf(fp, "%d", &bus_routes[i].stations[j]) != 1) {
                fclose(fp);
                return;
            }
        }
        for (int j = 0; j < bus_routes[i].station_count - 1; j++) {
            if (fscanf(fp, "%f", &bus_routes[i].distances[j]) != 1) {
                fclose(fp);
                return;
            }
        }
    }
    
    if (fscanf(fp, "%d", &walk_edge_count) != 1) {
        fclose(fp);
        return;
    }
    walk_edge_count = (walk_edge_count > MAX_EDGES) ? MAX_EDGES : walk_edge_count;
    for (int i = 0; i < walk_edge_count; i++) {
        int from, to;
        float distance;
        if (fscanf(fp, "%d %d %f", &from, &to, &distance) != 3) {
            printf("��ȡ���б� %d ʧ�ܣ��ļ���ʽ���ܴ���\n", i);
            fclose(fp);
            return;
        }
        if (from == 0 && to == 0 && distance == 0.00) {
            break;
        }
        walk_edges[i].from = from;
        walk_edges[i].to = to;
        walk_edges[i].distance = distance;
    }
    
    if (fscanf(fp, "%d %s", &password_set, admin_password) != 2) {
        fclose(fp);
        return;
    }
    
    fclose(fp);
    printf("�����Ѵ��ļ����ء�\n");
}

// ���²��б�
void update_walk_edges() {
    walk_edge_count = 0;
    
    // ���Ĭ�ϲ��б�
    int idx = 0;
    walk_edges[idx++] = (WalkEdge){1, 2, 0.25};   walk_edges[idx++] = (WalkEdge){2, 1, 0.25};
    walk_edges[idx++] = (WalkEdge){1, 11, 1.5};   walk_edges[idx++] = (WalkEdge){11, 1, 1.5};
    walk_edges[idx++] = (WalkEdge){1, 7, 1.0};    walk_edges[idx++] = (WalkEdge){7, 1, 1.0};
    walk_edges[idx++] = (WalkEdge){1, 6, 1.0};    walk_edges[idx++] = (WalkEdge){6, 1, 1.0};
    walk_edges[idx++] = (WalkEdge){2, 3, 0.25};   walk_edges[idx++] = (WalkEdge){3, 2, 0.25};
    walk_edges[idx++] = (WalkEdge){4, 5, 0.5};    walk_edges[idx++] = (WalkEdge){5, 4, 0.5};
    walk_edges[idx++] = (WalkEdge){7, 12, 0.5};   walk_edges[idx++] = (WalkEdge){12, 7, 0.5};
    walk_edges[idx++] = (WalkEdge){11, 12, 0.25}; walk_edges[idx++] = (WalkEdge){12, 11, 0.25};
    walk_edges[idx++] = (WalkEdge){12, 6, 1.0};   walk_edges[idx++] = (WalkEdge){6, 12, 1.0};
    walk_edges[idx++] = (WalkEdge){12, 13, 0.25}; walk_edges[idx++] = (WalkEdge){13, 12, 0.25};
    walk_edges[idx++] = (WalkEdge){6, 5, 1.0};    walk_edges[idx++] = (WalkEdge){5, 6, 1.0};
    walk_edges[idx++] = (WalkEdge){5, 14, 1.0};   walk_edges[idx++] = (WalkEdge){14, 5, 1.0};
    walk_edges[idx++] = (WalkEdge){6, 14, 1.0};   walk_edges[idx++] = (WalkEdge){14, 6, 1.0};
    walk_edges[idx++] = (WalkEdge){13, 14, 1.0};  walk_edges[idx++] = (WalkEdge){14, 13, 1.0};
    walk_edges[idx++] = (WalkEdge){14, 16, 1.0};  walk_edges[idx++] = (WalkEdge){16, 14, 1.0};
    walk_edges[idx++] = (WalkEdge){13, 16, 0.5};  walk_edges[idx++] = (WalkEdge){16, 13, 0.5};
    walk_edges[idx++] = (WalkEdge){16, 15, 0.5};  walk_edges[idx++] = (WalkEdge){15, 16, 0.5};
    walk_edges[idx++] = (WalkEdge){16, 10, 0.5};  walk_edges[idx++] = (WalkEdge){10, 16, 0.5};
    walk_edges[idx++] = (WalkEdge){10, 9, 1.0};   walk_edges[idx++] = (WalkEdge){9, 10, 1.0};
    walk_edges[idx++] = (WalkEdge){9, 15, 0.5};   walk_edges[idx++] = (WalkEdge){15, 9, 0.5};
    walk_edges[idx++] = (WalkEdge){9, 8, 0.5};    walk_edges[idx++] = (WalkEdge){8, 9, 0.5};
    walk_edges[idx++] = (WalkEdge){8, 3, 0.5};    walk_edges[idx++] = (WalkEdge){3, 8, 0.5};
    walk_edges[idx++] = (WalkEdge){9, 1, 1.5};    walk_edges[idx++] = (WalkEdge){1, 9, 1.5};
    walk_edges[idx++] = (WalkEdge){9, 3, 1.0};    walk_edges[idx++] = (WalkEdge){3, 9, 1.0};
    
    walk_edge_count = idx;
    
    // Ϊ������·�ϵ�����վ����Ӳ��б�
    for (int r = 0; r < route_count; r++) {
        for (int j = 0; j < bus_routes[r].station_count - 1; j++) {
            int from = bus_routes[r].stations[j];
            int to = bus_routes[r].stations[j+1];
            float distance = bus_routes[r].distances[j];
            
            int exists = 0;
            for (int k = 0; k < walk_edge_count; k++) {
                if ((walk_edges[k].from == from && walk_edges[k].to == to) ||
                    (walk_edges[k].from == to && walk_edges[k].to == from)) {
                    exists = 1;
                    break;
                }
            }
            
            if (!exists && walk_edge_count < MAX_EDGES - 2) {
                walk_edges[walk_edge_count++] = (WalkEdge){from, to, distance};
                walk_edges[walk_edge_count++] = (WalkEdge){to, from, distance};
            }
        }
    }
    
    save_data();
}

// ��ʼ��Ĭ������
void init_default_data() {
    station_count = 16;
    stations[0] = (Station){1, "�����", 1};
    stations[1] = (Station){2, "����", 0};
    stations[2] = (Station){3, "ͼ���", 1};
    stations[3] = (Station){4, "��ְ�������", 1};
    stations[4] = (Station){5, "ְ��ҽԺ", 1};
    stations[5] = (Station){6, "������", 1};
    stations[6] = (Station){7, "�����", 1};
    stations[7] = (Station){8, "�о���Ժ", 0};
    stations[8] = (Station){9, "�����¥", 1};
    stations[9] = (Station){10, "����G��", 1};
    stations[10] = (Station){11, "����C��", 0};
    stations[11] = (Station){12, "����B��", 1};
    stations[12] = (Station){13, "����D��", 1};
    stations[13] = (Station){14, "��������¥", 1};
    stations[14] = (Station){15, "����¥", 1};
    stations[15] = (Station){16, "��ʳ��", 1};
    
    route_count = 6;
    bus_routes[0] = (Route){1, 5, {1, 7, 12, 13, 16}, {1.0, 0.5, 0.25, 0.5}};
    bus_routes[1] = (Route){2, 4, {16, 10, 9, 3}, {0.5, 1.0, 1.0}};
    bus_routes[2] = (Route){3, 4, {1, 9, 15, 16}, {1.5, 0.5, 0.5}};
    bus_routes[3] = (Route){4, 4, {12, 6, 5, 4}, {1.0, 1.0, 0.5}};
    bus_routes[4] = (Route){5, 3, {5, 14, 16}, {1.0, 1.0}};
    bus_routes[5] = (Route){6, 4, {13, 14, 6, 1}, {1.0, 1.0, 1.0}};
    
    update_walk_edges();
}

// ����վ�����Ʋ���ID
int find_station_id(char *name) {
    for (int i = 0; i < station_count; i++) {
        if (strcmp(stations[i].name, name) == 0) {
            return stations[i].id;
        }
    }
    return -1;
}

// ��֤�����Ƿ�Ϊ��Ч������
int is_valid_float(char *str) {
    int has_dot = 0, has_digit = 0;
    for (int i = 0; str[i]; i++) {
        if (isdigit(str[i])) has_digit = 1;
        else if (str[i] == '.' && !has_dot) has_dot = 1;
        else return 0;
    }
    return has_digit;
}

// ����վ���Ƿ�Ϊ����վ��
void update_bus_station_status() {
    for (int i = 0; i < station_count; i++) {
        stations[i].is_bus_station = 0;
        for (int r = 0; r < route_count; r++) {
            for (int j = 0; j < bus_routes[r].station_count; j++) {
                if (bus_routes[r].stations[j] == stations[i].id) {
                    stations[i].is_bus_station = 1;
                    break;
                }
            }
            if (stations[i].is_bus_station) break;
        }
    }
}

// ��֤����
int verify_password() {
    if (!password_set) return 1;
    char input_password[MAX_PASSWORD];
    printf("���������Ա���룺");
    scanf("%s", input_password);
    return strcmp(input_password, admin_password) == 0;
}

// ��������
void manage_password() {
    int sub_choice;
    while (1) {
        printf("\n=== ������� ===\n");
        printf("1. �޸�����\n");
        printf("2. ȡ������\n");
        printf("3. ��������\n");
        printf("4. ���ع���Ա�˵�\n");
        printf("5. �˳�ϵͳ\n");
        printf("������ѡ�");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1:
                if (verify_password()) {
                    printf("�����������룺");
                    scanf("%s", admin_password);
                    password_set = 1;
                    save_data();
                    printf("�����޸ĳɹ���\n");
                } else {
                    printf("�������\n");
                }
                break;
            case 2:
                if (verify_password()) {
                    password_set = 0;
                    strcpy(admin_password, "");
                    save_data();
                    printf("������ȡ����\n");
                } else {
                    printf("�������\n");
                }
                break;
            case 3:
                printf("�����������룺");
                scanf("%s", admin_password);
                password_set = 1;
                save_data();
                printf("�������óɹ���\n");
                break;
            case 4:
                return;
            case 5:
                printf("��лʹ�ñ�ϵͳ��\n");
                exit(0);
            default:
                printf("��Чѡ�\n");
        }
    }
}

// �����վ��
void add_new_station() {
    if (station_count >= MAX_STATIONS) {
        printf("վ�������Ѵ����ޡ�\n");
        return;
    }
    
    Station new_station;
    new_station.id = station_count + 1;
    printf("������վ�����ƣ�");
    scanf("%s", new_station.name);
    new_station.is_bus_station = 1;
    
    stations[station_count++] = new_station;
    save_data();
    
    printf("��վ����ӳɹ���ID=%d, ����=%s, �Ƿ񹫽�վ��=%d\n", 
           new_station.id, new_station.name, new_station.is_bus_station);
}

// ��ӹ�����·
void add_bus_route() {
    if (route_count >= MAX_ROUTES) {
        printf("������·�Ѵ����ޡ�\n");
        return;
    }
    
    Route new_route;
    new_route.id = route_count + 1;
    printf("������վ��������");
    int station_count_input;
    if (scanf("%d", &station_count_input) != 1 || station_count_input <= 0 || station_count_input > MAX_STATIONS) {
        printf("վ��������Ч��\n");
        while (getchar() != '\n');
        return;
    }
    new_route.station_count = station_count_input;
    
    printf("�밴��ʻ˳������վ�����ƣ�ÿ��һ������\n");
    for (int i = 0; i < new_route.station_count; i++) {
        char name[MAX_NAME];
        scanf("%s", name);
        int id = find_station_id(name);
        if (id == -1) {
            printf("վ�� %s �����ڡ�\n", name);
            return;
        }
        new_route.stations[i] = id;
    }
    
    printf("����������վ�����루km���ÿո�ָ�����");
    for (int i = 0; i < new_route.station_count - 1; i++) {
        char dist_str[20];
        scanf("%s", dist_str);
        if (!is_valid_float(dist_str)) {
            printf("��Ч�������롣\n");
            return;
        }
        new_route.distances[i] = atof(dist_str);
        if (new_route.distances[i] <= 0) {
            printf("�������Ϊ������\n");
            return;
        }
    }
    
    bus_routes[route_count++] = new_route;
    update_bus_station_status();
    update_walk_edges();
    
    printf("�¹�����·��ӳɹ�����·ID=%d��վ����=%d\nվ�㣺", new_route.id, new_route.station_count);
    for (int i = 0; i < new_route.station_count; i++) {
        printf("%s", stations[new_route.stations[i]-1].name);
        if (i < new_route.station_count - 1) {
            printf("-(%.2fkm)->", new_route.distances[i]);
        }
    }
    printf("\n");
}

// �޸�վ����Ϣ
void modify_station_info(int route_idx) {
    printf("��ǰ��·ID=%d��վ�㣺", bus_routes[route_idx].id);
    for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
        printf("%s", stations[bus_routes[route_idx].stations[j]-1].name);
        if (j < bus_routes[route_idx].station_count - 1) {
            printf("-(%.2fkm)->", bus_routes[route_idx].distances[j]);
        }
    }
    printf("\n");
    
    int sub_choice;
    printf("1. �޸�վ������\n");
    printf("2. �޸�����վ�����\n");
    printf("3. ����\n");
    printf("������ѡ�");
    scanf("%d", &sub_choice);
    
    switch (sub_choice) {
        case 1: {
            char old_name[MAX_NAME], new_name[MAX_NAME];
            printf("������Ҫ�޸ĵ�վ�����ƣ�");
            scanf("%s", old_name);
            int station_idx = -1;
            for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
                if (strcmp(stations[bus_routes[route_idx].stations[j]-1].name, old_name) == 0) {
                    station_idx = bus_routes[route_idx].stations[j] - 1;
                    break;
                }
            }
            if (station_idx == -1) {
                printf("��·��δ�ҵ�վ�� %s��\n", old_name);
                return;
            }
            printf("��������վ�����ƣ�");
            scanf("%s", new_name);
            if (find_station_id(new_name) != -1) {
                printf("վ������ %s �Ѵ��ڡ�\n", new_name);
                return;
            }
            strcpy(stations[station_idx].name, new_name);
            save_data();
            printf("վ�������޸ĳɹ���%s -> %s\n", old_name, new_name);
            break;
        }
        case 2: {
            printf("������Ҫ�޸ĵ�����վ��ԣ���ʽ��վ��1 վ��2����");
            char name1[MAX_NAME], name2[MAX_NAME];
            scanf("%s %s", name1, name2);
            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
                if (strcmp(stations[bus_routes[route_idx].stations[j]-1].name, name1) == 0) idx1 = j;
                if (strcmp(stations[bus_routes[route_idx].stations[j]-1].name, name2) == 0) idx2 = j;
            }
            if (idx1 == -1 || idx2 == -1 || abs(idx1 - idx2) != 1) {
                printf("վ�����Ч�������վ�㡣\n");
                return;
            }
            int dist_idx = idx1 < idx2 ? idx1 : idx2;
            printf("������ %s �� %s ���¾��루km����", name1, name2);
            char dist_str[20];
            scanf("%s", dist_str);
            if (!is_valid_float(dist_str)) {
                printf("��Ч�������롣\n");
                return;
            }
            float new_dist = atof(dist_str);
            if (new_dist <= 0) {
                printf("�������Ϊ������\n");
                return;
            }
            bus_routes[route_idx].distances[dist_idx] = new_dist;
            save_data();
            printf("�����޸ĳɹ���%s �� %s �ľ������Ϊ %.2fkm\n", name1, name2, new_dist);
            break;
        }
        case 3:
            return;
        default:
            printf("��Чѡ�\n");
    }
}

// �޸Ĺ�����·
void modify_bus_route() {
    int route_id;
    printf("������Ҫ�޸ĵ���·ID��");
    if (scanf("%d", &route_id) != 1 || route_id <= 0) {
        printf("��Ч��·ID��\n");
        while (getchar() != '\n');
        return;
    }
    
    int route_idx = -1;
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            route_idx = i;
            break;
        }
    }
    if (route_idx == -1) {
        printf("δ�ҵ�����·��\n");
        return;
    }
    
    int sub_choice;
    printf("\n=== �޸Ĺ�����· ===\n");
    printf("1. ���޸�վ����Ϣ�����ƻ���룩\n");
    printf("2. ���޸Ĺ�����·��վ��˳���������\n");
    printf("3. ����\n");
    printf("������ѡ�");
    scanf("%d", &sub_choice);
    
    switch (sub_choice) {
        case 1:
            modify_station_info(route_idx);
            break;
        case 2: {
            printf("�������µ�վ��������");
            int new_count;
            if (scanf("%d", &new_count) != 1 || new_count <= 0 || new_count > MAX_STATIONS) {
                printf("վ��������Ч��\n");
                while (getchar() != '\n');
                return;
            }
            bus_routes[route_idx].station_count = new_count;
            
            printf("�밴����ʻ˳������վ�����ƣ�ÿ��һ������\n");
            for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
                char name[MAX_NAME];
                scanf("%s", name);
                int id = find_station_id(name);
                if (id == -1) {
                    printf("վ�� %s �����ڡ�\n", name);
                    return;
                }
                bus_routes[route_idx].stations[j] = id;
            }
            
            printf("�������µ�����վ�����루km���ÿո�ָ�����");
            for (int j = 0; j < bus_routes[route_idx].station_count - 1; j++) {
                char dist_str[20];
                scanf("%s", dist_str);
                if (!is_valid_float(dist_str)) {
                    printf("��Ч�������롣\n");
                    return;
                }
                bus_routes[route_idx].distances[j] = atof(dist_str);
                if (bus_routes[route_idx].distances[j] <= 0) {
                    printf("�������Ϊ������\n");
                    return;
                }
            }
            
            update_bus_station_status();
            update_walk_edges();
            printf("������·�޸ĳɹ�����·ID=%d��վ����=%d\nվ�㣺", bus_routes[route_idx].id, bus_routes[route_idx].station_count);
            for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
                printf("%s", stations[bus_routes[route_idx].stations[j]-1].name);
                if (j < bus_routes[route_idx].station_count - 1) {
                    printf("-(%.2fkm)->", bus_routes[route_idx].distances[j]);
                }
            }
            printf("\n");
            break;
        }
        case 3:
            return;
        default:
            printf("��Чѡ�\n");
    }
}

// ����·��ɾ��վ��
void delete_station_from_route() {
    int route_id;
    char station_name[MAX_NAME];
    printf("��������·ID��");
    if (scanf("%d", &route_id) != 1 || route_id <= 0) {
        printf("��Ч��·ID��\n");
        while (getchar() != '\n');
        return;
    }
    printf("������Ҫɾ����վ�����ƣ�");
    scanf("%s", station_name);
    
    int station_id = find_station_id(station_name);
    if (station_id == -1) {
        printf("վ�� %s �����ڡ�\n", station_name);
        return;
    }
    
    int route_idx = -1;
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            route_idx = i;
            break;
        }
    }
    if (route_idx == -1) {
        printf("δ�ҵ�����·��\n");
        return;
    }
    
    int delete_idx = -1;
    for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
        if (bus_routes[route_idx].stations[j] == station_id) {
            delete_idx = j;
            break;
        }
    }
    if (delete_idx == -1) {
        printf("��·��δ�ҵ���վ�㡣\n");
        return;
    }
    
    int new_count = bus_routes[route_idx].station_count - 1;
    int new_stations[MAX_STATIONS];
    float new_distances[MAX_STATIONS];
    
    for (int j = 0, k = 0; j < bus_routes[route_idx].station_count; j++) {
        if (j != delete_idx) {
            new_stations[k] = bus_routes[route_idx].stations[j];
            if (j < bus_routes[route_idx].station_count - 1 && k < new_count - 1) {
                new_distances[k] = bus_routes[route_idx].distances[j];
            }
            k++;
        }
    }
    
    if (delete_idx > 0 && delete_idx < bus_routes[route_idx].station_count - 1) {
        printf("������վ�� %s �� %s ���¾��루km����", 
               stations[new_stations[delete_idx-1]-1].name, stations[new_stations[delete_idx]-1].name);
        char dist_str[20];
        scanf("%s", dist_str);
        if (!is_valid_float(dist_str)) {
            printf("��Ч�������롣\n");
            return;
        }
        new_distances[delete_idx-1] = atof(dist_str);
        if (new_distances[delete_idx-1] <= 0) {
            printf("�������Ϊ������\n");
            return;
        }
    }
    
    bus_routes[route_idx].station_count = new_count;
    for (int j = 0; j < new_count; j++) {
        bus_routes[route_idx].stations[j] = new_stations[j];
        if (j < new_count - 1) {
            bus_routes[route_idx].distances[j] = new_distances[j];
        }
    }
    
    update_bus_station_status();
    update_walk_edges();
    printf("վ��ɾ���ɹ�����·ID=%d��ʣ��վ����=%d\nվ�㣺", bus_routes[route_idx].id, bus_routes[route_idx].station_count);
    for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
        printf("%s", stations[bus_routes[route_idx].stations[j]-1].name);
        if (j < bus_routes[route_idx].station_count - 1) {
            printf("-(%.2fkm)->", bus_routes[route_idx].distances[j]);
        }
    }
    printf("\n");
}

// ���վ�㵽��·
void add_station_to_route() {
    int route_id;
    char station_name[MAX_NAME];
    int position;
    printf("��������·ID��");
    if (scanf("%d", &route_id) != 1 || route_id <= 0) {
        printf("��Ч��·ID��\n");
        while (getchar() != '\n');
        return;
    }
    printf("������Ҫ��ӵ�վ�����ƣ�");
    scanf("%s", station_name);
    printf("���������λ�ã�0Ϊ��ʼλ�ã���");
    if (scanf("%d", &position) != 1) {
        printf("��Чλ�����롣\n");
        while (getchar() != '\n');
        return;
    }
    
    int station_id = find_station_id(station_name);
    if (station_id == -1) {
        printf("վ�� %s �����ڡ�\n", station_name);
        return;
    }
    
    int route_idx = -1;
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            route_idx = i;
            break;
        }
    }
    if (route_idx == -1) {
        printf("δ�ҵ�����·��\n");
        return;
    }
    
    if (position < 0 || position > bus_routes[route_idx].station_count) {
        printf("λ����Ч��\n");
        return;
    }
    
    for (int j = bus_routes[route_idx].station_count; j > position; j--) {
        bus_routes[route_idx].stations[j] = bus_routes[route_idx].stations[j-1];
        if (j < bus_routes[route_idx].station_count) {
            bus_routes[route_idx].distances[j] = bus_routes[route_idx].distances[j-1];
        }
    }
    
    bus_routes[route_idx].stations[position] = station_id;
    bus_routes[route_idx].station_count++;
    stations[station_id-1].is_bus_station = 1;
    
    if (position < bus_routes[route_idx].station_count - 1) {
        printf("�������վ�㵽��һվ�ľ��루km����");
        char dist_str[20];
        scanf("%s", dist_str);
        if (!is_valid_float(dist_str) || atof(dist_str) <= 0) {
            printf("��Ч�������롣\n");
            return;
        }
        bus_routes[route_idx].distances[position] = atof(dist_str);
    }
    if (position > 0) {
        printf("��������һվ����վ��ľ��루km����");
        char dist_str[20];
        scanf("%s", dist_str);
        if (!is_valid_float(dist_str) || atof(dist_str) <= 0) {
            printf("��Ч�������롣\n");
            return;
        }
        bus_routes[route_idx].distances[position-1] = atof(dist_str);
    }
    
    update_bus_station_status();
    update_walk_edges();
    printf("վ����ӳɹ�����·ID=%d��վ����=%d\nվ�㣺", bus_routes[route_idx].id, bus_routes[route_idx].station_count);
    for (int j = 0; j < bus_routes[route_idx].station_count; j++) {
        printf("%s", stations[bus_routes[route_idx].stations[j]-1].name);
        if (j < bus_routes[route_idx].station_count - 1) {
            printf("-(%.2fkm)->", bus_routes[route_idx].distances[j]);
        }
    }
    printf("\n");
}

// ��ѯվ�㾭���Ĺ�����·
void query_station_routes() {
    char station_name[MAX_NAME];
    printf("������վ�����ƣ�");
    scanf("%s", station_name);
    
    int station_id = find_station_id(station_name);
    if (station_id == -1) {
        printf("δ�ҵ���վ�㡣\n");
        return;
    }
    
    printf("����%s�Ĺ�����·��\n", station_name);
    int found = 0;
    for (int i = 0; i < route_count; i++) {
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            if (bus_routes[i].stations[j] == station_id) {
                found = 1;
                printf("��·%d��", bus_routes[i].id);
                float total_distance = 0.0;
                for (int k = 0; k < bus_routes[i].station_count; k++) {
                    printf("%s", stations[bus_routes[i].stations[k]-1].name);
                    if (k < bus_routes[i].station_count - 1) {
                        printf("-(%.2fkm)->", bus_routes[i].distances[k]);
                        total_distance += bus_routes[i].distances[k];
                    }
                }
                printf("\n�ܾ��룺%.2fkm����ʱ�䣺%.2f����\n", total_distance, total_distance / BUS_SPEED);
            }
        }
    }
    if (!found) {
        printf("��վ��û�й�����·������\n");
    }
}

// ��ʾ���й�����·
void display_all_routes() {
    printf("����У�ڹ�����·��\n");
    for (int i = 0; i < route_count; i++) {
        printf("��·%d��", bus_routes[i].id);
        float total_distance = 0.0;
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            printf("%s", stations[bus_routes[i].stations[j]-1].name);
            if (j < bus_routes[i].station_count - 1) {
                printf("-(%.2fkm)->", bus_routes[i].distances[j]);
                total_distance += bus_routes[i].distances[j];
            }
        }
        printf("\n�ܾ��룺%.2fkm����ʱ�䣺%.2f����\n", total_distance, total_distance / BUS_SPEED);
    }
}

// Dijkstra�㷨
Path dijkstra(int start_id, int end_id, int mode) {
    float dist[MAX_STATIONS]; // ��Ҫ������ʱ��/���˴���/���룩
    float total_time[MAX_STATIONS]; // ����ʱ���������ٻ���ģʽ�Ƚϣ�
    float total_dist[MAX_STATIONS]; // �ܾ���
    int prev[MAX_STATIONS];
    int visited[MAX_STATIONS];
    char modes[MAX_STATIONS][10];
    int transfers[MAX_STATIONS];
    int prev_route[MAX_STATIONS]; // ��¼��һ��ʹ�õ���·ID
    
    Path result = {{0}, 0, 99999.0, 99999.0, 999, {""}};
    
    for (int i = 0; i < station_count; i++) {
        dist[i] = 99999.0;
        total_time[i] = 99999.0;
        total_dist[i] = 99999.0;
        prev[i] = -1;
        visited[i] = 0;
        transfers[i] = 999;
        prev_route[i] = -1;
        strcpy(modes[i], "");
    }
    
    dist[start_id-1] = 0;
    total_time[start_id-1] = 0;
    total_dist[start_id-1] = 0;
    transfers[start_id-1] = 0;
    
    // ����ǹ���վ���յ㣨���ٻ��ˣ�
    int target_id = end_id;
    if (stations[end_id-1].is_bus_station == 0 && mode == 1) {
        float min_dist = 99999.0;
        for (int i = 0; i < walk_edge_count; i++) {
            if (walk_edges[i].from == end_id && stations[walk_edges[i].to-1].is_bus_station) {
                if (walk_edges[i].distance < min_dist) {
                    min_dist = walk_edges[i].distance;
                    target_id = walk_edges[i].to;
                }
            }
            if (walk_edges[i].to == end_id && stations[walk_edges[i].from-1].is_bus_station) {
                if (walk_edges[i].distance < min_dist) {
                    min_dist = walk_edges[i].distance;
                    target_id = walk_edges[i].from;
                }
            }
        }
    }
    
    for (int i = 0; i < station_count; i++) {
        int min_idx = -1;
        float min_dist = 99999.0;
        
        for (int j = 0; j < station_count; j++) {
            if (!visited[j]) {
                if (mode == 1) {
                    if (min_idx == -1 || transfers[j] < transfers[min_idx] || 
                        (transfers[j] == transfers[min_idx] && total_time[j] < total_time[min_idx])) {
                        min_dist = dist[j];
                        min_idx = j;
                    }
                } else if (dist[j] < min_dist) {
                    min_dist = dist[j];
                    min_idx = j;
                }
            }
        }
        
        if (min_idx == -1 || min_idx == target_id-1) break;
        visited[min_idx] = 1;
        
        // ������·
        for (int r = 0; r < route_count; r++) {
            int found = 0;
            int route_start_idx = -1;
            for (int j = 0; j < bus_routes[r].station_count; j++) {
                if (bus_routes[r].stations[j] == min_idx + 1) {
                    found = 1;
                    route_start_idx = j;
                    break;
                }
            }
            if (found) {
                for (int j = route_start_idx + 1; j < bus_routes[r].station_count; j++) {
                    float segment_dist = 0.0;
                    int transfer = 0;
                    
                    if (prev[min_idx] != -1 && strcmp(modes[min_idx], "����") == 0 && prev_route[min_idx] != bus_routes[r].id) {
                        transfer = 1;
                    }
                    
                    for (int k = route_start_idx; k < j; k++) {
                        segment_dist += bus_routes[r].distances[k];
                    }
                    float time = segment_dist / BUS_SPEED;
                    int next_station = bus_routes[r].stations[j] - 1;
                    
                    if (!visited[next_station]) {
                        float new_dist = (mode == 0) ? dist[min_idx] + time :
                                        (mode == 1) ? dist[min_idx] + (transfer ? 1 : 0) :
                                        dist[min_idx] + segment_dist;
                        float new_total_time = total_time[min_idx] + time;
                        float new_total_dist = total_dist[min_idx] + segment_dist;
                        int new_transfers = transfers[min_idx] + transfer;
                        
                        if (mode == 1) {
                            if (new_transfers < transfers[next_station] || 
                                (new_transfers == transfers[next_station] && new_total_time < total_time[next_station])) {
                                dist[next_station] = new_dist;
                                total_time[next_station] = new_total_time;
                                total_dist[next_station] = new_total_dist;
                                prev[next_station] = min_idx;
                                transfers[next_station] = new_transfers;
                                strcpy(modes[next_station], "����");
                                prev_route[next_station] = bus_routes[r].id;
                            }
                        } else if (new_dist < dist[next_station]) {
                            dist[next_station] = new_dist;
                            total_time[next_station] = new_total_time;
                            total_dist[next_station] = new_total_dist;
                            prev[next_station] = min_idx;
                            transfers[next_station] = new_transfers;
                            strcpy(modes[next_station], "����");
                            prev_route[next_station] = bus_routes[r].id;
                        }
                    }
                }
            }
        }
        
        // ���б�
        for (int j = 0; j < walk_edge_count; j++) {
            if (walk_edges[j].from == min_idx + 1 && !visited[walk_edges[j].to-1]) {
                float time = walk_edges[j].distance / WALK_SPEED;
                float new_dist = (mode == 0) ? dist[min_idx] + time :
                                (mode == 1) ? dist[min_idx] :
                                dist[min_idx] + walk_edges[j].distance;
                float new_total_time = total_time[min_idx] + time;
                float new_total_dist = total_dist[min_idx] + walk_edges[j].distance;
                
                if (mode == 1) {
                    if (transfers[min_idx] < transfers[walk_edges[j].to-1] || 
                        (transfers[min_idx] == transfers[walk_edges[j].to-1] && new_total_time < total_time[walk_edges[j].to-1])) {
                        dist[walk_edges[j].to-1] = new_dist;
                        total_time[walk_edges[j].to-1] = new_total_time;
                        total_dist[walk_edges[j].to-1] = new_total_dist;
                        prev[walk_edges[j].to-1] = min_idx;
                        transfers[walk_edges[j].to-1] = transfers[min_idx];
                        strcpy(modes[walk_edges[j].to-1], "����");
                        prev_route[walk_edges[j].to-1] = -1;
                    }
                } else if (new_dist < dist[walk_edges[j].to-1]) {
                    dist[walk_edges[j].to-1] = new_dist;
                    total_time[walk_edges[j].to-1] = new_total_time;
                    total_dist[walk_edges[j].to-1] = new_total_dist;
                    prev[walk_edges[j].to-1] = min_idx;
                    transfers[walk_edges[j].to-1] = transfers[min_idx];
                    strcpy(modes[walk_edges[j].to-1], "����");
                    prev_route[walk_edges[j].to-1] = -1;
                }
            }
        }
    }
    
    // ����ǹ���վ���յ�
    if (target_id != end_id) {
        for (int j = 0; j < walk_edge_count; j++) {
            if ((walk_edges[j].from == target_id && walk_edges[j].to == end_id) || 
                (walk_edges[j].to == target_id && walk_edges[j].from == end_id)) {
                float time = walk_edges[j].distance / WALK_SPEED;
                dist[end_id-1] = (mode == 0) ? dist[target_id-1] + time :
                                (mode == 1) ? dist[target_id-1] :
                                dist[target_id-1] + walk_edges[j].distance;
                total_time[end_id-1] = total_time[target_id-1] + time;
                total_dist[end_id-1] = total_dist[target_id-1] + walk_edges[j].distance;
                prev[end_id-1] = target_id-1;
                transfers[end_id-1] = transfers[target_id-1];
                strcpy(modes[end_id-1], "����");
                prev_route[end_id-1] = -1;
                break;
            }
        }
    }
    
    if (dist[end_id-1] != 99999.0) {
        result.time = total_time[end_id-1];
        result.distance = total_dist[end_id-1];
        result.path_length = 0;
        int current = end_id - 1;
        while (current != -1) {
            result.path[result.path_length] = current + 1;
            strcpy(result.modes[result.path_length], modes[current]);
            result.path_length++;
            current = prev[current];
        }
        result.transfers = transfers[end_id-1];
    }
    
    return result;
}

// ·�߹滮
void plan_route(int mode) {
    char start_name[MAX_NAME], end_name[MAX_NAME];
    int start_id, end_id;
    
    if (mode != 2) {
        printf("������������ƣ�");
        scanf("%s", start_name);
        printf("�������յ����ƣ�");
        scanf("%s", end_name);
        
        start_id = find_station_id(start_name);
        end_id = find_station_id(end_name);
        
        if (start_id == -1 || end_id == -1) {
            printf("�����յ㲻���ڡ�\n");
            return;
        }
    } else {
        start_id = 1; // �����
        printf("�������յ����ƣ�");
        scanf("%s", end_name);
        end_id = find_station_id(end_name);
        if (end_id == -1) {
            printf("�յ㲻���ڡ�\n");
            return;
        }
    }
    
    Path result = dijkstra(start_id, end_id, mode);
    
    if (result.path_length == 0) {
        printf("�޷��ҵ����ʵ�·�ߡ�\n");
        return;
    }
    
    printf("����·�ߣ�%s����\n", mode == 0 ? "���ʱ��" : mode == 1 ? "���ٻ���" : "��̾��루������ɣ�");
    float total_distance = 0.0;
    float total_time = 0.0;
    for (int i = result.path_length - 1; i >= 0; i--) {
        printf("%s", stations[result.path[i]-1].name);
        if (i > 0) {
            printf(" %s ", result.modes[i-1]);
            if (strcmp(result.modes[i-1], "����") == 0) {
                for (int j = 0; j < walk_edge_count; j++) {
                    if (walk_edges[j].from == result.path[i] && walk_edges[j].to == result.path[i-1]) {
                        printf("(%.2fkm)", walk_edges[j].distance);
                        total_distance += walk_edges[j].distance;
                        total_time += walk_edges[j].distance / WALK_SPEED;
                        break;
                    }
                }
            } else {
                int route_id = -1;
                float segment_distance = 0.0;
                for (int r = 0; r < route_count; r++) {
                    int found_from = -1, found_to = -1;
                    for (int j = 0; j < bus_routes[r].station_count; j++) {
                        if (bus_routes[r].stations[j] == result.path[i]) found_from = j;
                        if (bus_routes[r].stations[j] == result.path[i-1]) found_to = j;
                    }
                    if (found_from != -1 && found_to != -1 && found_from < found_to) {
                        route_id = bus_routes[r].id;
                        for (int j = found_from; j < found_to; j++) {
                            segment_distance += bus_routes[r].distances[j];
                        }
                        break;
                    }
                }
                printf("(%.2fkm, ��·%d)", segment_distance, route_id);
                total_distance += segment_distance;
                total_time += segment_distance / BUS_SPEED;
            }
            printf(" -> ");
        }
    }
    printf("\n�ܾ��룺%.2fkm\n��ʱ�䣺%.2f����\n���˴�����%d\n", 
           total_distance, total_time, result.transfers);
}

// ����Ա�˵�
void admin_menu() {
    int sub_choice;
    while (1) {
        printf("\n=== ����Ա���� ===\n");
        printf("1. �����վ��\n");
        printf("2. ����������·\n");
        printf("3. �޸Ĺ�����·\n");
        printf("4. ����·��ɾ��վ��\n");
        printf("5. ���վ�㵽��·\n");
        printf("6. �������\n");
        printf("7. �鿴���й�����·\n");
        printf("8. �������˵�\n");
        printf("9. �˳�ϵͳ\n");
        printf("������ѡ�");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1: add_new_station(); break;
            case 2: add_bus_route(); break;
            case 3: modify_bus_route(); break;
            case 4: delete_station_from_route(); break;
            case 5: add_station_to_route(); break;
            case 6: manage_password(); break;
            case 7: display_all_routes(); break;
            case 8: return;
            case 9:
                printf("��лʹ�ñ�ϵͳ��\n");
                exit(0);
            default: printf("��Чѡ�\n");
        }
    }
}

// ѧ���˵�
void student_menu() {
    int sub_choice;
    while (1) {
        printf("\n=== ѧ������ ===\n");
        printf("1. ��ѯվ�㾭���Ĺ�����·\n");
        printf("2. ��ʾ���й�����·\n");
        printf("3. ���ʱ��·�߹滮\n");
        printf("4. ���ٻ���·�߹滮\n");
        printf("5. ������ɳ�������̾���·��\n");
        printf("6. �������˵�\n");
        printf("7. �˳�ϵͳ\n");
        printf("������ѡ�");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1: query_station_routes(); break;
            case 2: display_all_routes(); break;
            case 3: plan_route(0); break;
            case 4: plan_route(1); break;
            case 5: plan_route(2); break;
            case 6: return;
            case 7:
                printf("��лʹ�ñ�ϵͳ��\n");
                exit(0);
            default: printf("��Чѡ�\n");
        }
    }
}

// ���˵�
void menu() {
    int choice;
    while (1) {
        printf("\n=== У԰������ѯϵͳ ===\n");
        printf("1. ����Ա����\n");
        printf("2. ѧ������\n");
        printf("3. �˳�ϵͳ\n");
        printf("������ѡ�");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (verify_password()) {
                    admin_menu();
                } else {
                    printf("�������\n");
                }
                break;
            case 2:
                student_menu();
                break;
            case 3:
                printf("��лʹ�ñ�ϵͳ��\n");
                return;
            default:
                printf("��Чѡ�\n");
        }
    }
}

int main() {
    load_data();
    if (station_count == 0) {
        init_default_data();
    }
    menu();
    return 0;
}
