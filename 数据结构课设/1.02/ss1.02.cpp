#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 50
#define MAX_ROUTES 10
#define MAX_NAME 50
#define MAX_EDGES 100
#define BUS_SPEED 0.25 // 公交车速度，km/min
#define WALK_SPEED 0.1 // 步行速度，km/min
#define MAX_PASSWORD 20 // 密码最大长度

// 站点结构体
typedef struct {
    int id;
    char name[MAX_NAME];
    int is_bus_station; // 1表示公交站点，0表示非公交站点
} Station;

// 路线结构体
typedef struct {
    int id;
    int station_count;
    int stations[MAX_STATIONS];
    float distances[MAX_STATIONS]; // 相邻站点间的距离
} Route;

// 步行路径结构体
typedef struct {
    int from;
    int to;
    float distance;
} WalkEdge;

// 系统数据
Station stations[MAX_STATIONS];
Route bus_routes[MAX_ROUTES];
WalkEdge walk_edges[MAX_EDGES];
int station_count = 0;
int route_count = 0;
int walk_edge_count = 0;
char admin_password[MAX_PASSWORD] = "admin123"; // 默认密码
int password_set = 1; // 密码是否已设置

// 文件操作：保存数据
void save_data() {
    FILE *fp = fopen("bus_data.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    
    // 保存站点
    fprintf(fp, "%d\n", station_count);
    for (int i = 0; i < station_count; i++) {
        fprintf(fp, "%d %s %d\n", stations[i].id, stations[i].name, stations[i].is_bus_station);
    }
    
    // 保存公交路线
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
    
    // 保存步行路径
    fprintf(fp, "%d\n", walk_edge_count);
    for (int i = 0; i < walk_edge_count; i++) {
        fprintf(fp, "%d %d %.2f\n", walk_edges[i].from, walk_edges[i].to, walk_edges[i].distance);
    }
    
    // 保存密码
    fprintf(fp, "%d %s\n", password_set, admin_password);
    
    fclose(fp);
    printf("数据已保存到文件。\n");
}

// 文件操作：加载数据
void load_data() {
    FILE *fp = fopen("bus_data.txt", "r");
    if (!fp) {
        printf("文件打开失败，将使用默认数据初始化！\n");
        return;
    }
    
    // 读取站点
    fscanf(fp, "%d", &station_count);
    for (int i = 0; i < station_count; i++) {
        fscanf(fp, "%d %s %d", &stations[i].id, stations[i].name, &stations[i].is_bus_station);
    }
    
    // 读取公交路线
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
    
    // 读取步行路径
    fscanf(fp, "%d", &walk_edge_count);
    for (int i = 0; i < walk_edge_count; i++) {
        fscanf(fp, "%d %d %f", &walk_edges[i].from, &walk_edges[i].to, &walk_edges[i].distance);
    }
    
    // 读取密码
    fscanf(fp, "%d %s", &password_set, admin_password);
    
    fclose(fp);
    printf("数据已从文件加载。\n");
}

// 初始化默认数据
void init_default_data() {
    // 初始化站点
    station_count = 16;
    stations[0] = (Station){1, "五棵松", 1};
    stations[1] = (Station){2, "教务处", 0};
    stations[2] = (Station){3, "图书馆", 1};
    stations[3] = (Station){4, "教职工活动中心", 1};
    stations[4] = (Station){5, "职工医院", 1};
    stations[5] = (Station){6, "大礼堂", 1};
    stations[6] = (Station){7, "三岔口", 1};
    stations[7] = (Station){8, "研究生院", 0};
    stations[8] = (Station){9, "耒耜大楼", 1};
    stations[9] = (Station){10, "宿舍G区", 1};
    stations[10] = (Station){11, "宿舍C区", 0};
    stations[11] = (Station){12, "宿舍B区", 1};
    stations[12] = (Station){13, "宿舍D区", 1};
    stations[13] = (Station){14, "行政二号楼", 1};
    stations[14] = (Station){15, "京江楼", 1};
    stations[15] = (Station){16, "六食堂", 1};
    
    // 初始化公交路线
    route_count = 5;
    bus_routes[0] = (Route){1, 5, {1, 7, 12, 13, 16}, {1.0, 0.5, 0.25, 0.5}};
    bus_routes[1] = (Route){2, 4, {16, 10, 9, 3}, {0.5, 1.0, 1.0}};
    bus_routes[2] = (Route){3, 4, {1, 9, 15, 16}, {1.5, 0.5, 0.5}};
    bus_routes[3] = (Route){4, 4, {12, 6, 5, 4}, {1.0, 1.0, 0.5}};
    bus_routes[4] = (Route){5, 3, {5, 14, 16}, {1.0, 1.0}};
    
    // 初始化步行路径（双向）
    walk_edge_count = 46;
    walk_edges[0] = (WalkEdge){1, 2, 0.25};
    walk_edges[1] = (WalkEdge){2, 1, 0.25};
    walk_edges[2] = (WalkEdge){1, 11, 1.5};
    walk_edges[3] = (WalkEdge){11, 1, 1.5};
    walk_edges[4] = (WalkEdge){1, 7, 1.0};
    walk_edges[5] = (WalkEdge){7, 1, 1.0};
    walk_edges[6] = (WalkEdge){1, 6, 1.0};
    walk_edges[7] = (WalkEdge){6, 1, 1.0};
    walk_edges[8] = (WalkEdge){2, 3, 0.25};
    walk_edges[9] = (WalkEdge){3, 2, 0.25};
    walk_edges[10] = (WalkEdge){4, 5, 0.5};
    walk_edges[11] = (WalkEdge){5, 4, 0.5};
    walk_edges[12] = (WalkEdge){7, 12, 0.5};
    walk_edges[13] = (WalkEdge){12, 7, 0.5};
    walk_edges[14] = (WalkEdge){11, 12, 0.25};
    walk_edges[15] = (WalkEdge){12, 11, 0.25};
    walk_edges[16] = (WalkEdge){12, 6, 1.0};
    walk_edges[17] = (WalkEdge){6, 12, 1.0};
    walk_edges[18] = (WalkEdge){12, 13, 0.25};
    walk_edges[19] = (WalkEdge){13, 12, 0.25};
    walk_edges[20] = (WalkEdge){6, 5, 1.0};
    walk_edges[21] = (WalkEdge){5, 6, 1.0};
    walk_edges[22] = (WalkEdge){5, 14, 1.0};
    walk_edges[23] = (WalkEdge){14, 5, 1.0};
    walk_edges[24] = (WalkEdge){6, 14, 1.0};
    walk_edges[25] = (WalkEdge){14, 6, 1.0};
    walk_edges[26] = (WalkEdge){13, 14, 1.0};
    walk_edges[27] = (WalkEdge){14, 13, 1.0};
    walk_edges[28] = (WalkEdge){14, 16, 1.0};
    walk_edges[29] = (WalkEdge){16, 14, 1.0};
    walk_edges[30] = (WalkEdge){13, 16, 0.5};
    walk_edges[31] = (WalkEdge){16, 13, 0.5};
    walk_edges[32] = (WalkEdge){16, 15, 0.5};
    walk_edges[33] = (WalkEdge){15, 16, 0.5};
    walk_edges[34] = (WalkEdge){16, 10, 0.5};
    walk_edges[35] = (WalkEdge){10, 16, 0.5};
    walk_edges[36] = (WalkEdge){10, 9, 1.0};
    walk_edges[37] = (WalkEdge){9, 10, 1.0};
    walk_edges[38] = (WalkEdge){9, 15, 0.5};
    walk_edges[39] = (WalkEdge){15, 9, 0.5};
    walk_edges[40] = (WalkEdge){9, 8, 0.5};
    walk_edges[41] = (WalkEdge){8, 9, 0.5};
    walk_edges[42] = (WalkEdge){8, 3, 0.5};
    walk_edges[43] = (WalkEdge){3, 8, 0.5};
    walk_edges[44] = (WalkEdge){9, 1, 1.5};
    walk_edges[45] = (WalkEdge){1, 9, 1.5};
    
    save_data();
}

// 查找站点ID
int find_station_id(char *name) {
    for (int i = 0; i < station_count; i++) {
        if (strcmp(stations[i].name, name) == 0) {
            return stations[i].id;
        }
    }
    return -1;
}

// 管理员功能：验证密码
int verify_password() {
    if (!password_set) return 1; // 未设置密码时直接通过
    char input_password[MAX_PASSWORD];
    printf("请输入管理员密码：");
    scanf("%s", input_password);
    return strcmp(input_password, admin_password) == 0;
}

// 管理员功能：密码管理
void manage_password() {
    int sub_choice;
    while (1) {
        printf("\n=== 密码管理 ===\n");
        printf("1. 修改密码\n");
        printf("2. 删除密码\n");
        printf("3. 设置密码\n");
        printf("4. 返回管理员菜单\n");
        printf("5. 退出系统\n");
        printf("请输入选择：");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1: // 修改密码
                if (verify_password()) {
                    printf("请输入新密码：");
                    scanf("%s", admin_password);
                    password_set = 1;
                    save_data();
                    printf("密码修改成功！\n");
                } else {
                    printf("密码错误！\n");
                }
                break;
            case 2: // 删除密码
                if (verify_password()) {
                    password_set = 0;
                    strcpy(admin_password, "");
                    save_data();
                    printf("密码已删除！\n");
                } else {
                    printf("密码错误！\n");
                }
                break;
            case 3: // 设置密码
                printf("请输入新密码：");
                scanf("%s", admin_password);
                password_set = 1;
                save_data();
                printf("密码设置成功！\n");
                break;
            case 4:
                return;
            case 5:
                printf("感谢使用本系统！\n");
                exit(0);
            default:
                printf("无效选择！\n");
        }
    }
}

// 管理员功能：添加新站点
void add_new_station() {
    if (station_count >= MAX_STATIONS) {
        printf("站点数量已达上限！\n");
        return;
    }
    
    Station new_station;
    new_station.id = station_count + 1;
    printf("请输入站点名称：");
    scanf("%s", new_station.name);
    printf("是否为公交站点（1为是，0为否）：");
    scanf("%d", &new_station.is_bus_station);
    
    stations[station_count++] = new_station;
    
    // 添加步行路径
    char choice;
    do {
        printf("是否为新站点添加步行路径？（y/n）：");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            if (walk_edge_count >= MAX_EDGES - 1) {
                printf("步行路径数量已达上限！\n");
                break;
            }
            printf("请输入目标站点名称：");
            char target_name[MAX_NAME];
            scanf("%s", target_name);
            int target_id = find_station_id(target_name);
            if (target_id == -1) {
                printf("目标站点不存在！\n");
                continue;
            }
            printf("请输入步行距离（km）：");
            float distance;
            scanf("%f", &distance);
            
            walk_edges[walk_edge_count++] = (WalkEdge){new_station.id, target_id, distance};
            walk_edges[walk_edge_count++] = (WalkEdge){target_id, new_station.id, distance}; // 双向路径
            printf("步行路径添加成功！\n");
        }
    } while (choice == 'y' || choice == 'Y');
    
    save_data();
    printf("新站点添加成功！\n");
}

// 管理员功能：新增公交线路
void add_bus_route() {
    if (route_count >= MAX_ROUTES) {
        printf("公交线路已满！\n");
        return;
    }
    
    Route new_route;
    new_route.id = route_count + 1;
    printf("请输入站点数量：");
    scanf("%d", &new_route.station_count);
    
    printf("请输入站点ID（用空格分隔）：");
    for (int i = 0; i < new_route.station_count; i++) {
        scanf("%d", &new_route.stations[i]);
        if (new_route.stations[i] > station_count || new_route.stations[i] <= 0) {
            printf("站点ID无效！\n");
            return;
        }
    }
    
    printf("请输入相邻站点间距离（km，用空格分隔）：");
    for (int i = 0; i < new_route.station_count - 1; i++) {
        scanf("%f", &new_route.distances[i]);
    }
    
    bus_routes[route_count++] = new_route;
    save_data();
    printf("新增公交线路成功！\n");
}

// 管理员功能：修改公交线路
void modify_bus_route() {
    int route_id;
    printf("请输入要修改的线路ID：");
    scanf("%d", &route_id);
    
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            printf("请输入新的站点数量：");
            scanf("%d", &bus_routes[i].station_count);
            
            printf("请输入新的站点ID（用空格分隔）：");
            for (int j = 0; j < bus_routes[i].station_count; j++) {
                scanf("%d", &bus_routes[i].stations[j]);
                if (bus_routes[i].stations[j] > station_count || bus_routes[i].stations[j] <= 0) {
                    printf("站点ID无效！\n");
                    return;
                }
            }
            
            printf("请输入新的相邻站点间距离（km，用空格分隔）：");
            for (int j = 0; j < bus_routes[i].station_count - 1; j++) {
                scanf("%f", &bus_routes[i].distances[j]);
            }
            
            save_data();
            printf("修改公交线路成功！\n");
            return;
        }
    }
    printf("未找到该线路！\n");
}

// 管理员功能：删除线路中的站点
void delete_station_from_route() {
    int route_id, station_id;
    printf("请输入线路ID：");
    scanf("%d", &route_id);
    printf("请输入要删除的站点ID：");
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
            printf("删除站点成功！\n");
            return;
        }
    }
    printf("未找到该线路！\n");
}

// 管理员功能：增加站点到线路
void add_station_to_route() {
    int route_id, station_id, position;
    printf("请输入线路ID：");
    scanf("%d", &route_id);
    printf("请输入要添加的站点ID：");
    scanf("%d", &station_id);
    printf("请输入添加位置（0为起始位置）：");
    scanf("%d", &position);
    
    for (int i = 0; i < route_count; i++) {
        if (bus_routes[i].id == route_id) {
            if (position < 0 || position > bus_routes[i].station_count) {
                printf("位置无效！\n");
                return;
            }
            if (station_id > station_count || station_id <= 0) {
                printf("站点ID无效！\n");
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
                printf("请输入新站点到下一站点的距离（km）：");
                scanf("%f", &bus_routes[i].distances[position]);
            }
            if (position > 0) {
                printf("请输入上一站点到新站点的距离（km）：");
                scanf("%f", &bus_routes[i].distances[position-1]);
            }
            
            save_data();
            printf("添加站点成功！\n");
            return;
        }
    }
    printf("未找到该线路！\n");
}

// 学生功能：查询站点经过的公交线路
void query_station_routes() {
    char station_name[MAX_NAME];
    printf("请输入站点名称：");
    scanf("%s", station_name);
    
    int station_id = find_station_id(station_name);
    if (station_id == -1) {
        printf("未找到该站点！\n");
        return;
    }
    
    printf("经过%s的公交线路：\n", station_name);
    int found = 0;
    for (int i = 0; i < route_count; i++) {
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            if (bus_routes[i].stations[j] == station_id) {
                found = 1;
                printf("线路%d：", bus_routes[i].id);
                float total_distance = 0.0;
                for (int k = 0; k < bus_routes[i].station_count; k++) {
                    printf("%s", stations[bus_routes[i].stations[k]-1].name);
                    if (k < bus_routes[i].station_count - 1) {
                        printf("-(%.2fkm)->", bus_routes[i].distances[k]);
                        total_distance += bus_routes[i].distances[k];
                    }
                }
                printf("\n总距离：%.2fkm，总时间：%.2f分钟\n", total_distance, total_distance / BUS_SPEED);
            }
        }
    }
    if (!found) {
        printf("该站点没有公交线路经过。\n");
    }
}

// 学生功能：输出所有公交路线
void display_all_routes() {
    printf("所有校内公交路线：\n");
    for (int i = 0; i < route_count; i++) {
        printf("线路%d：", bus_routes[i].id);
        float total_distance = 0.0;
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            printf("%s", stations[bus_routes[i].stations[j]-1].name);
            if (j < bus_routes[i].station_count - 1) {
                printf("-(%.2fkm)->", bus_routes[i].distances[j]);
                total_distance += bus_routes[i].distances[j];
            }
        }
        printf("\n总距离：%.2fkm，总时间：%.2f分钟\n", total_distance, total_distance / BUS_SPEED);
    }
}

// Dijkstra算法实现最优路径
typedef struct {
    int path[MAX_STATIONS];
    int path_length;
    float time;
    float distance;
    int transfers;
    char modes[MAX_STATIONS][10]; // 记录每段路径的交通方式
} Path;

Path dijkstra(int start_id, int end_id, int mode) { // mode: 0 for min time, 1 for min transfers, 2 for min distance
    float dist[MAX_STATIONS];
    int prev[MAX_STATIONS];
    int visited[MAX_STATIONS];
    char modes[MAX_STATIONS][MAX_STATIONS][10];
    int transfers[MAX_STATIONS];
    
    Path result = {{0}, 0, 99999.0, 99999.0, 999, {""}};
    
    for (int i = 0; i < station_count; i++) {
        dist[i] = 99999.0;
        prev[i] = -1;
        visited[i] = 0;
        transfers[i] = 999;
        strcpy(modes[i][0], "");
    }
    
    dist[start_id-1] = 0;
    transfers[start_id-1] = 0;
    
    // 如果终点不是公交站点，找到最近的公交站点
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
            if (!visited[j] && (mode == 1 ? transfers[j] < transfers[min_idx] || 
                             (transfers[j] == transfers[min_idx] && dist[j] < min_dist) : dist[j] < min_dist)) {
                min_dist = dist[j];
                min_idx = j;
            }
        }
        
        if (min_idx == -1 || min_idx == target_id-1) break;
        visited[min_idx] = 1;
        
        // 检查公交路线
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
                        float total_dist = 0.0;
                        int transfer = (j != route_start_idx + 1 && j != route_start_idx - 1) ? 1 : 0;
                        int start = j < route_start_idx ? j : route_start_idx;
                        int end = j < route_start_idx ? route_start_idx : j;
                        for (int k = start; k < end; k++) {
                            total_dist += bus_routes[r].distances[k];
                        }
                        float time = total_dist / BUS_SPEED;
                        int next_station = bus_routes[r].stations[j] - 1;
                        if (!visited[next_station]) {
                            float new_dist = mode == 0 ? dist[min_idx] + time : 
                                           mode == 1 ? dist[min_idx] + (transfer ? 1 : 0) : 
                                           dist[min_idx] + total_dist;
                            int new_transfers = transfers[min_idx] + transfer;
                            if (mode == 1 ? new_transfers < transfers[next_station] || 
                                            (new_transfers == transfers[next_station] && dist[next_station] > new_dist) :
                                            new_dist < dist[next_station]) {
                                dist[next_station] = new_dist;
                                prev[next_station] = min_idx;
                                transfers[next_station] = new_transfers;
                                strcpy(modes[next_station][0], "公交");
                            }
                        }
                    }
                }
            }
        }
        
        // 检查步行路径
        for (int j = 0; j < walk_edge_count; j++) {
            if (walk_edges[j].from == min_idx + 1 && !visited[walk_edges[j].to-1]) {
                float time = walk_edges[j].distance / WALK_SPEED;
                float new_dist = mode == 0 ? dist[min_idx] + time : 
                                mode == 1 ? dist[min_idx] + time : 
                                dist[min_idx] + walk_edges[j].distance;
                if (new_dist < dist[walk_edges[j].to-1]) {
                    dist[walk_edges[j].to-1] = new_dist;
                    prev[walk_edges[j].to-1] = min_idx;
                    transfers[walk_edges[j].to-1] = transfers[min_idx];
                    strcpy(modes[walk_edges[j].to-1][0], "步行");
                }
            }
            if (walk_edges[j].to == min_idx + 1 && !visited[walk_edges[j].from-1]) {
                float time = walk_edges[j].distance / WALK_SPEED;
                float new_dist = mode == 0 ? dist[min_idx] + time : 
                                mode == 1 ? dist[min_idx] + time : 
                                dist[min_idx] + walk_edges[j].distance;
                if (new_dist < dist[walk_edges[j].from-1]) {
                    dist[walk_edges[j].from-1] = new_dist;
                    prev[walk_edges[j].from-1] = min_idx;
                    transfers[walk_edges[j].from-1] = transfers[min_idx];
                    strcpy(modes[walk_edges[j].from-1][0], "步行");
                }
            }
        }
    }
    
    // 如果终点不是公交站点，添加从目标公交站点到终点的步行路径
    if (target_id != end_id) {
        for (int j = 0; j < walk_edge_count; j++) {
            if ((walk_edges[j].from == target_id && walk_edges[j].to == end_id) || 
                (walk_edges[j].to == target_id && walk_edges[j].from == end_id)) {
                dist[end_id-1] = dist[target_id-1] + (mode == 0 ? walk_edges[j].distance / WALK_SPEED : 
                                                     mode == 1 ? 0 : walk_edges[j].distance);
                prev[end_id-1] = target_id-1;
                transfers[end_id-1] = transfers[target_id-1];
                strcpy(modes[end_id-1][0], "步行");
                break;
            }
        }
    }
    
    if (dist[end_id-1] != 99999.0) {
        result.time = dist[end_id-1];
        result.distance = 0.0;
        result.path_length = 0;
        int current = end_id - 1;
        while (current != -1) {
            result.path[result.path_length] = current + 1;
            strcpy(result.modes[result.path_length], modes[current][0]);
            result.path_length++;
            current = prev[current];
        }
        
        // 计算总距离
        for (int i = result.path_length - 1; i > 0; i--) {
            int from = result.path[i];
            int to = result.path[i-1];
            if (strcmp(result.modes[i-1], "步行") == 0) {
                for (int j = 0; j < walk_edge_count; j++) {
                    if ((walk_edges[j].from == from && walk_edges[j].to == to) || 
                        (walk_edges[j].from == to && walk_edges[j].to == from)) {
                        result.distance += walk_edges[j].distance;
                        break;
                    }
                }
            } else {
                for (int r = 0; r < route_count; r++) {
                    int found_from = -1, found_to = -1;
                    for (int j = 0; j < bus_routes[r].station_count; j++) {
                        if (bus_routes[r].stations[j] == from) found_from = j;
                        if (bus_routes[r].stations[j] == to) found_to = j;
                    }
                    if (found_from != -1 && found_to != -1) {
                        int start = found_from < found_to ? found_from : found_to;
                        int end = found_from < found_to ? found_to : found_from;
                        for (int j = start; j < end; j++) {
                            result.distance += bus_routes[r].distances[j];
                        }
                        break;
                    }
                }
            }
        }
        
        result.transfers = transfers[end_id-1];
    }
    
    return result;
}

// 学生功能：路线规划
void plan_route(int mode) { // mode: 0 for min time, 1 for min transfers, 2 for min distance from 五棵松
    char start_name[MAX_NAME], end_name[MAX_NAME];
    int start_id, end_id;
    
    if (mode != 2) {
        printf("请输入起点名称：");
        scanf("%s", start_name);
        printf("请输入终点名称：");
        scanf("%s", end_name);
        
        start_id = find_station_id(start_name);
        end_id = find_station_id(end_name);
        
        if (start_id == -1 || end_id == -1) {
            printf("起点或终点不存在！\n");
            return;
        }
    } else {
        start_id = 1; // 五棵松
        printf("请输入终点名称：");
        scanf("%s", end_name);
        end_id = find_station_id(end_name);
        if (end_id == -1) {
            printf("终点不存在！\n");
            return;
        }
    }
    
    Path result = dijkstra(start_id, end_id, mode);
    
    if (result.path_length == 0) {
        printf("无法到达目的地！\n");
        return;
    }
    
    printf("最优路线（%s）：\n", mode == 0 ? "最短时间" : mode == 1 ? "最少换乘" : "最短距离（从五棵松）");
    float total_distance = 0.0;
    for (int i = result.path_length - 1; i >= 0; i--) {
        printf("%s", stations[result.path[i]-1].name);
        if (i > 0) {
            printf(" %s ", result.modes[i-1]);
            if (strcmp(result.modes[i-1], "步行") == 0) {
                for (int j = 0; j < walk_edge_count; j++) {
                    if ((walk_edges[j].from == result.path[i] && walk_edges[j].to == result.path[i-1]) || 
                        (walk_edges[j].from == result.path[i-1] && walk_edges[j].to == result.path[i])) {
                        printf("(%.2fkm)", walk_edges[j].distance);
                        total_distance += walk_edges[j].distance;
                        break;
                    }
                }
            } else {
                int route_id = -1;
                for (int r = 0; r < route_count; r++) {
                    int found_from = -1, found_to = -1;
                    for (int j = 0; j < bus_routes[r].station_count; j++) {
                        if (bus_routes[r].stations[j] == result.path[i]) found_from = j;
                        if (bus_routes[r].stations[j] == result.path[i-1]) found_to = j;
                    }
                    if (found_from != -1 && found_to != -1) {
                        route_id = bus_routes[r].id;
                        float segment_distance = 0.0;
                        int start = found_from < found_to ? found_from : found_to;
                        int end = found_from < found_to ? found_to : found_from;
                        for (int j = start; j < end; j++) {
                            segment_distance += bus_routes[r].distances[j];
                        }
                        printf("(%.2fkm, 线路%d)", segment_distance, route_id);
                        total_distance += segment_distance;
                        break;
                    }
                }
            }
            printf(" -> ");
        }
    }
    printf("\n总距离：%.2fkm\n总时间：%.2f分钟\n换乘次数：%d\n", 
           total_distance, result.time, result.transfers);
}

// 管理员菜单
void admin_menu() {
    int sub_choice;
    while (1) {
        printf("\n=== 管理员功能 ===\n");
        printf("1. 添加新站点\n");
        printf("2. 新增公交线路\n");
        printf("3. 修改公交线路\n");
        printf("4. 删除线路中的站点\n");
        printf("5. 增加站点到线路\n");
        printf("6. 密码管理\n");
        printf("7. 返回主菜单\n");
        printf("8. 退出系统\n");
        printf("请输入选择：");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1: add_new_station(); break;
            case 2: add_bus_route(); break;
            case 3: modify_bus_route(); break;
            case 4: delete_station_from_route(); break;
            case 5: add_station_to_route(); break;
            case 6: manage_password(); break;
            case 7: return;
            case 8:
                printf("感谢使用本系统！\n");
                exit(0);
            default: printf("无效选择！\n");
        }
    }
}

// 学生菜单
void student_menu() {
    int sub_choice;
    while (1) {
        printf("\n=== 学生功能 ===\n");
        printf("1. 查询站点经过的公交线路\n");
        printf("2. 显示所有公交路线\n");
        printf("3. 最短时间路线规划\n");
        printf("4. 最少换乘路线规划\n");
        printf("5. 从五棵松出发的最短距离路线\n");
        printf("6. 返回主菜单\n");
        printf("7. 退出系统\n");
        printf("请输入选择：");
        scanf("%d", &sub_choice);
        
        switch (sub_choice) {
            case 1: query_station_routes(); break;
            case 2: display_all_routes(); break;
            case 3: plan_route(0); break;
            case 4: plan_route(1); break;
            case 5: plan_route(2); break;
            case 6: return;
            case 7:
                printf("感谢使用本系统！\n");
                exit(0);
            default: printf("无效选择！\n");
        }
    }
}

// 主菜单
void menu() {
    int choice;
    while (1) {
        printf("\n=== 江苏大学公交查询系统 ===\n");
        printf("1. 管理员功能\n");
        printf("2. 学生功能\n");
        printf("3. 退出系统\n");
        printf("请输入选择：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (verify_password()) {
                    admin_menu();
                } else {
                    printf("密码错误！\n");
                }
                break;
            case 2:
                student_menu();
                break;
            case 3:
                printf("感谢使用本系统！\n");
                return;
            default:
                printf("无效选择！\n");
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
