#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 50
#define MAX_ROUTES 10
#define MAX_NAME 50
#define MAX_EDGES 100

// վ��ṹ��
typedef struct {
    int id;
    char name[MAX_NAME];
    int is_bus_station; // 1��ʾ����վ�㣬0��ʾ�ǹ���վ��
} Station;

// ·�߽ṹ��
typedef struct {
    int id;
    int station_count;
    int stations[MAX_STATIONS];
    float distances[MAX_STATIONS]; // ����վ���ľ���
} Route;

// ����·���ṹ��
typedef struct {
    int from;
    int to;
    float distance;
} WalkEdge;

// ϵͳ����
Station stations[MAX_STATIONS];
Route bus_routes[MAX_ROUTES];
WalkEdge walk_edges[MAX_EDGES];
int station_count = 0;
int route_count = 0;
int walk_edge_count = 0;

// �ļ�����
void save_data() {
    FILE *fp = fopen("bus_data.txt", "w");
    if (!fp) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    
    // ����վ��
    fprintf(fp, "%d\n", station_count);
    for (int i = 0; i < station_count; i++) {
        fprintf(fp, "%d %s %d\n", stations[i].id, stations[i].name, stations[i].is_bus_station);
    }
    
    // ���湫��·��
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
    
    // ���沽��·��
    fprintf(fp, "%d\n", walk_edge_count);
    for (int i = 0; i < walk_edge_count; i++) {
        fprintf(fp, "%d %d %.2f\n", walk_edges[i].from, walk_edges[i].to, walk_edges[i].distance);
    }
    
    fclose(fp);
    printf("�����ѱ��浽�ļ���\n");
}

void load_data() {
    FILE *fp = fopen("bus_data.txt", "r");
    if (!fp) {
        printf("�ļ���ʧ�ܣ���ʹ��Ĭ�����ݳ�ʼ����\n");
        return;
    }
    
    // ��ȡվ��
    fscanf(fp, "%d", &station_count);
    for (int i = 0; i < station_count; i++) {
        fscanf(fp, "%d %s %d", &stations[i].id, stations[i].name, &stations[i].is_bus_station);
    }
    
    // ��ȡ����·��
    fscanf(fp, "%d", &route_count);
    for (int i = 0; i < route_count; i++) {
        fscanf(fp, "%d %d", &bus_routes[i].id, &bus_routes[i].station_count);
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            fscanf(fp, "%d", &bus_routes[i].stations[j]);
        }
        for (int j = 0; j < bus_routes[i].station_count - 1; j++) {
            fscanf(fp, "%f", &bus_routes[i].distances[j]);
        }
    }
    
    // ��ȡ����·��
    fscanf(fp, "%d", &walk_edge_count);
    for (int i = 0; i < walk_edge_count; i++) {
        fscanf(fp, "%d %d %f", &walk_edges[i].from, &walk_edges[i].to, &walk_edges[i].distance);
    }
    
    fclose(fp);
    printf("�����Ѵ��ļ����ء�\n");
}

// ��ʼ��Ĭ������
void init_default_data() {
    // ��ʼ��վ��
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
    
    // ��ʼ������·��
    route_count = 5;
    bus_routes[0] = (Route){1, 5, {1, 7, 12, 13, 16}, {1.0, 0.5, 0.25, 0.5}};
    bus_routes[1] = (Route){2, 4, {16, 10, 9, 3}, {0.5, 1.0, 1.0}};
    bus_routes[2] = (Route){3, 4, {1, 9, 15, 16}, {1.5, 0.5, 0.5}};
    bus_routes[3] = (Route){4, 4, {12, 6, 5, 4}, {1.0, 1.0, 0.5}};
    bus_routes[4] = (Route){5, 3, {5, 14, 16}, {1.0, 1.0}};
    
    // ��ʼ������·��
    walk_edge_count = 24;
    walk_edges[0] = (WalkEdge){1, 2, 0.25};
    walk_edges[1] = (WalkEdge){1, 11, 1.5};
    walk_edges[2] = (WalkEdge){1, 7, 1.0};
    walk_edges[3] = (WalkEdge){1, 6, 1.0};
    walk_edges[4] = (WalkEdge){2, 3, 0.25};
    walk_edges[5] = (WalkEdge){4, 5, 0.5};
    walk_edges[6] = (WalkEdge){7, 12, 0.5};
    walk_edges[7] = (WalkEdge){11, 12, 0.25};
    walk_edges[8] = (WalkEdge){12, 6, 1.0};
    walk_edges[9] = (WalkEdge){12, 13, 0.25};
    walk_edges[10] = (WalkEdge){6, 5, 1.0};
    walk_edges[11] = (WalkEdge){5, 14, 1.0};
    walk_edges[12] = (WalkEdge){6, 14, 1.0};
    walk_edges[13] = (WalkEdge){13, 14, 1.0};
    walk_edges[14] = (WalkEdge){14, 16, 1.0};
    walk_edges[15] = (WalkEdge){13, 16, 0.5};
    walk_edges[16] = (WalkEdge){16, 15, 0.5};
    walk_edges[17] = (WalkEdge){16, 10, 0.5};
    walk_edges[18] = (WalkEdge){10, 9, 1.0};
    walk_edges[19] = (WalkEdge){9, 15, 0.5};
    walk_edges[20] = (WalkEdge){9, 8, 0.5};
    walk_edges[21] = (WalkEdge){8, 3, 0.5};
    walk_edges[22] = (WalkEdge){9, 1, 1.5};
    walk_edges[23] = (WalkEdge){2, 1, 0.25}; // ˫��·��
    
    save_data();
}

// ����վ��ID
int find_station_id(char *name) {
    for (int i = 0; i < station_count; i++) {
        if (strcmp(stations[i].name, name) == 0) {
            return stations[i].id;
        }
    }
    return -1;
}

// ����Ա���ܣ�����������·
void add_bus_route() {
    if (route_count >= MAX_ROUTES) {
        printf("������·������\n");
        return;
    }
    
    Route new_route;
    new_route.id = route_count + 1;
    printf("������վ��������");
    scanf("%d", &new_route.station_count);
    
    printf("������վ��ID���ÿո�ָ�����");
    for (int i = 0; i < new_route.station_count; i++) {
        scanf("%d", &new_route.stations[i]);
    }
    
    printf("����������վ�����루�ÿո�ָ�����");
    for (int i = 0; i < new_route.station_count - 1; i++) {
        scanf("%f", &new_route.distances[i]);
    }
    
    bus_routes[route_count++] = new_route;
    save_data();
    printf("����������·�ɹ���\n");
}

// ����Ա���ܣ��޸Ĺ�����·
void modify_bus_route() {
    int route_id;
    printf("������Ҫ�޸ĵ���·ID��");
    scanf("%d", &route_id);
    
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            printf("�������µ�վ��������");
            scanf("%d", &bus_routes[i].station_count);
            
            printf("�������µ�վ��ID���ÿո�ָ�����");
            for (int j = 0; j < bus_routes[i].station_count; j++) {
                scanf("%d", &bus_routes[i].stations[j]);
            }
            
            printf("�������µ�����վ�����루�ÿո�ָ�����");
            for (int j = 0; j < bus_routes[i].station_count - 1; j++) {
                scanf("%f", &bus_routes[i].distances[j]);
            }
            
            save_data();
            printf("�޸Ĺ�����·�ɹ���\n");
            return;
        }
    }
    printf("δ�ҵ�����·��\n");
}

// ����Ա���ܣ�ɾ��վ��
void delete_station_from_route() {
    int route_id, station_id;
    printf("��������·ID��");
    scanf("%d", &route_id);
    printf("������Ҫɾ����վ��ID��");
    scanf("%d", &station_id);
    
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            int new_count = 0;
            int new_stations[MAX_STATIONS];
            float new_distances[MAX_STATIONS];
            
            for (int j = 0; j < bus_routes[i].station_count; j++) {
                if (bus_routes[i].stations[j] != station_id) {
                    new_stations[new_count] = bus_routes[i].stations[j];
                    if (j < bus_routes[i].station_count - 1 && new_count < bus_routes[i].station_count - 1) {
                        new_distances[new_count] = bus_routes[i].distances[j];
                    }
                    new_count++;
                }
            }
            
            bus_routes[i].station_count = new_count;
            for (int j = 0; j < new_count; j++) {
                bus_routes[i].stations[j] = new_stations[j];
                if (j < new_count - 1) {
                    bus_routes[i].distances[j] = new_distances[j];
                }
            }
            
            save_data();
            printf("ɾ��վ��ɹ���\n");
            return;
        }
    }
    printf("δ�ҵ�����·��\n");
}

// ����Ա���ܣ�����վ��
void add_station_to_route() {
    int route_id, station_id, position;
    printf("��������·ID��");
    scanf("%d", &route_id);
    printf("������Ҫ��ӵ�վ��ID��");
    scanf("%d", &station_id);
    printf("���������λ�ã�0Ϊ��ʼλ�ã���");
    scanf("%d", &position);
    
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            if (position < 0 || position > bus_routes[i].station_count) {
                printf("λ����Ч��\n");
                return;
            }
            
            for (int j = bus_routes[i].station_count; j > position; j--) {
                bus_routes[i].stations[j] = bus_routes[i].stations[j-1];
                if (j < bus_routes[i].station_count) {
                    bus_routes[i].distances[j] = bus_routes[i].distances[j-1];
                }
            }
            
            bus_routes[i].stations[position] = station_id;
            bus_routes[i].station_count++;
            
            if (position < bus_routes[i].station_count - 1) {
                printf("��������վ�㵽��һվ��ľ��룺");
                scanf("%f", &bus_routes[i].distances[position]);
            }
            if (position > 0) {
                printf("��������һվ�㵽��վ��ľ��룺");
                scanf("%f", &bus_routes[i].distances[position-1]);
            }
            
            save_data();
            printf("���վ��ɹ���\n");
            return;
        }
    }
    printf("δ�ҵ�����·��\n");
}

// ѧ�����ܣ���ѯվ�㾭���Ĺ�����·
void query_station_routes() {
    char station_name[MAX_NAME];
    printf("������վ�����ƣ�");
    scanf("%s", station_name);
    
    int station_id = find_station_id(station_name);
    if (station_id == -1) {
        printf("δ�ҵ���վ�㣡\n");
        return;
    }
    
    printf("����%s�Ĺ�����·��\n", station_name);
    for (int i = 0; i < route_count; i++) {
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            if (bus_routes[i].stations[j] == station_id) {
                printf("��·%d��", bus_routes[i].id);
                for (int k = 0; k < bus_routes[i].station_count; k++) {
                    printf("%s", stations[bus_routes[i].stations[k]-1].name);
                    if (k < bus_routes[i].station_count - 1) {
                        printf("-(%.2fkm)->", bus_routes[i].distances[k]);
                    }
                }
                printf("\n");
                break;
            }
        }
    }
}

// ѧ�����ܣ�������й���·��
void display_all_routes() {
    printf("����У�ڹ���·�ߣ�\n");
    for (int i = 0; i < route_count; i++) {
        printf("��·%d��", bus_routes[i].id);
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            printf("%s", stations[bus_routes[i].stations[j]-1].name);
            if (j < bus_routes[i].station_count - 1) {
                printf("-(%.2fkm)->", bus_routes[i].distances[j]);
            }
        }
        printf("\n");
    }
}

// Dijkstra�㷨ʵ�����ʱ��·��
typedef struct {
    int path[MAX_STATIONS];
    int path_length;
    float time;
    int transfers;
} Path;

Path dijkstra(int start_id, int end_id, int mode) { // mode: 0 for min time, 1 for min transfers
    float dist[MAX_STATIONS];
    int prev[MAX_STATIONS];
    int visited[MAX_STATIONS];
    Path result = {{0}, 0, 99999.0, 999};
    
    for (int i = 0; i < station_count; i++) {
        dist[i] = 99999.0;
        prev[i] = -1;
        visited[i] = 0;
    }
    
    dist[start_id-1] = 0;
    
    for (int i = 0; i < station_count; i++) {
        int min_idx = -1;
        float min_dist = 99999.0;
        
        for (int j = 0; j < station_count; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_idx = j;
            }
        }
        
        if (min_idx == -1) break;
        visited[min_idx] = 1;
        
        // ��鹫��·��
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
                for (int j = 0; j < bus_routes[r].station_count; j++) {
                    if (j != route_start_idx) {
                        float total_dist = 0;
                        int transfer = (j < route_start_idx) ? 1 : 0;
                        for (int k = (j < route_start_idx) ? j : route_start_idx; 
                             k < (j < route_start_idx ? route_start_idx : j); k++) {
                            total_dist += bus_routes[r].distances[k];
                        }
                        float time = total_dist / 0.25; // �������ٶ�0.25km/min
                        int next_station = bus_routes[r].stations[j] - 1;
                        if (!visited[next_station]) {
                            float new_dist = mode == 0 ? dist[min_idx] + time : 
                                           dist[min_idx] + transfer;
                            if (new_dist < dist[next_station]) {
                                dist[next_station] = new_dist;
                                prev[next_station] = min_idx;
                            }
                        }
                    }
                }
            }
        }
        
        // ��鲽��·��
        for (int j = 0; j < walk_edge_count; j++) {
            if (walk_edges[j].from == min_idx + 1 && !visited[walk_edges[j].to-1]) {
                float time = walk_edges[j].distance / 0.1; // �����ٶ�0.1km/min
                if (dist[min_idx] + time < dist[walk_edges[j].to-1]) {
                    dist[walk_edges[j].to-1] = dist[min_idx] + time;
                    prev[walk_edges[j].to-1] = min_idx;
                }
            }
            if (walk_edges[j].to == min_idx + 1 && !visited[walk_edges[j].from-1]) {
                float time = walk_edges[j].distance / 0.1;
                if (dist[min_idx] + time < dist[walk_edges[j].from-1]) {
                    dist[walk_edges[j].from-1] = dist[min_idx] + time;
                    prev[walk_edges[j].from-1] = min_idx;
                }
            }
        }
    }
    
    if (dist[end_id-1] != 99999.0) {
        result.time = dist[end_id-1];
        result.path_length = 0;
        int current = end_id - 1;
        while (current != -1) {
            result.path[result.path_length++] = current + 1;
            current = prev[current];
        }
        
        // ���㻻�˴���
        result.transfers = 0;
        int last_route = -1;
        for (int i = result.path_length - 2; i >= 0; i--) {
            int found = 0;
            for (int r = 0; r < route_count; r++) {
                int has_prev = 0, has_curr = 0;
                for (int j = 0; j < bus_routes[r].station_count; j++) {
                    if (bus_routes[r].stations[j] == result.path[i]) has_curr = 1;
                    if (bus_routes[r].stations[j] == result.path[i+1]) has_prev = 1;
                }
                if (has_prev && has_curr) {
                    if (last_route != -1 && last_route != r) {
                        result.transfers++;
                    }
                    last_route = r;
                    found = 1;
                    break;
                }
            }
        }
    }
    
    return result;
}

// ѧ�����ܣ�����·�߹滮
void plan_route(int mode) { // mode: 0 for min time, 1 for min transfers, 2 for from �����
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
            printf("�����յ㲻���ڣ�\n");
            return;
        }
    } else {
        start_id = 1; // �����
        printf("�������յ����ƣ�");
        scanf("%s", end_name);
        end_id = find_station_id(end_name);
        if (end_id == -1) {
            printf("�յ㲻���ڣ�\n");
            return;
        }
    }
    
    Path result = dijkstra(start_id, end_id, mode);
    
    if (result.path_length == 0) {
        printf("�޷�����Ŀ�ĵأ�\n");
        return;
    }
    
    printf("����·�ߣ�%s����", mode == 0 ? "���ʱ��" : mode == 1 ? "���ٻ���" : "������ɳ���");
    for (int i = result.path_length - 1; i >= 0; i--) {
        printf("%s", stations[result.path[i]-1].name);
        if (i > 0) printf(" -> ");
    }
    printf("\n��ʱ�䣺%.2f����\n���˴�����%d\n", result.time, result.transfers);
}

// ���˵�
void menu() {
    int choice, sub_choice;
    while (1) {
        printf("\n=== ���մ�ѧ������ѯϵͳ ===\n");
        printf("1. ����Ա����\n");
        printf("2. ѧ������\n");
        printf("3. �˳�\n");
        printf("������ѡ��");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\n=== ����Ա���� ===\n");
            printf("1. ����������·\n");
            printf("2. �޸Ĺ�����·\n");
            printf("3. ɾ����·�е�վ��\n");
            printf("4. ����վ�㵽��·\n");
            printf("5. �������˵�\n");
            printf("������ѡ��");
            scanf("%d", &sub_choice);
            
            switch (sub_choice) {
                case 1: add_bus_route(); break;
                case 2: modify_bus_route(); break;
                case 3: delete_station_from_route(); break;
                case 4: add_station_to_route(); break;
                case 5: break;
                default: printf("��Чѡ��\n");
            }
        } else if (choice == 2) {
            printf("\n=== ѧ������ ===\n");
            printf("1. ��ѯվ�㾭���Ĺ�����·\n");
            printf("2. ��ʾ���й���·��\n");
            printf("3. ���ʱ��·�߹滮\n");
            printf("4. ���ٻ���·�߹滮\n");
            printf("5. ������ɳ��������·��\n");
            printf("6. �������˵�\n");
            printf("������ѡ��");
            scanf("%d", &sub_choice);
            
            switch (sub_choice) {
                case 1: query_station_routes(); break;
                case 2: display_all_routes(); break;
                case 3: plan_route(0); break;
                case 4: plan_route(1); break;
                case 5: plan_route(2); break;
                case 6: break;
                default: printf("��Чѡ��\n");
            }
        } else if (choice == 3) {
            printf("��лʹ�ñ�ϵͳ��\n");
            break;
        } else {
            printf("��Чѡ��\n");
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
