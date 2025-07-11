#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATIONS 50
#define MAX_ROUTES 10
#define MAX_NAME 50
#define MAX_EDGES 100

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

// 文件操作
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
    
    fclose(fp);
    printf("数据已保存到文件。\n");
}

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
    
    // 初始化步行路径
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
    walk_edges[23] = (WalkEdge){2, 1, 0.25}; // 双向路径
    
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
    }
    
    printf("请输入相邻站点间距离（用空格分隔）：");
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
            }
            
            printf("请输入新的相邻站点间距离（用空格分隔）：");
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

// 管理员功能：删除站点
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

// 管理员功能：增加站点
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
            
            for (int j = bus_routes[i].station_count; j > position; j--) {
                bus_routes[i].stations[j] = bus_routes[i].stations[j-1];
                if (j < bus_routes[i].station_count) {
                    bus_routes[i].distances[j] = bus_routes[i].distances[j-1];
                }
            }
            
            bus_routes[i].stations[position] = station_id;
            bus_routes[i].station_count++;
            
            if (position < bus_routes[i].station_count - 1) {
                printf("请输入新站点到下一站点的距离：");
                scanf("%f", &bus_routes[i].distances[position]);
            }
            if (position > 0) {
                printf("请输入上一站点到新站点的距离：");
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
    for (int i = 0; i < route_count; i++) {
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            if (bus_routes[i].stations[j] == station_id) {
                printf("线路%d：", bus_routes[i].id);
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

// 学生功能：输出所有公交路线
void display_all_routes() {
    printf("所有校内公交路线：\n");
    for (int i = 0; i < route_count; i++) {
        printf("线路%d：", bus_routes[i].id);
        for (int j = 0; j < bus_routes[i].station_count; j++) {
            printf("%s", stations[bus_routes[i].stations[j]-1].name);
            if (j < bus_routes[i].station_count - 1) {
                printf("-(%.2fkm)->", bus_routes[i].distances[j]);
            }
        }
        printf("\n");
    }
}

// Dijkstra算法实现最短时间路径
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
                        float total_dist = 0;
                        int transfer = (j < route_start_idx) ? 1 : 0;
                        for (int k = (j < route_start_idx) ? j : route_start_idx; 
                             k < (j < route_start_idx ? route_start_idx : j); k++) {
                            total_dist += bus_routes[r].distances[k];
                        }
                        float time = total_dist / 0.25; // 公交车速度0.25km/min
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
        
        // 检查步行路径
        for (int j = 0; j < walk_edge_count; j++) {
            if (walk_edges[j].from == min_idx + 1 && !visited[walk_edges[j].to-1]) {
                float time = walk_edges[j].distance / 0.1; // 步行速度0.1km/min
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
        
        // 计算换乘次数
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

// 学生功能：最优路线规划
void plan_route(int mode) { // mode: 0 for min time, 1 for min transfers, 2 for from 五棵松
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
    
    printf("最优路线（%s）：", mode == 0 ? "最短时间" : mode == 1 ? "最少换乘" : "从五棵松出发");
    for (int i = result.path_length - 1; i >= 0; i--) {
        printf("%s", stations[result.path[i]-1].name);
        if (i > 0) printf(" -> ");
    }
    printf("\n总时间：%.2f分钟\n换乘次数：%d\n", result.time, result.transfers);
}

// 主菜单
void menu() {
    int choice, sub_choice;
    while (1) {
        printf("\n=== 江苏大学公交查询系统 ===\n");
        printf("1. 管理员功能\n");
        printf("2. 学生功能\n");
        printf("3. 退出\n");
        printf("请输入选择：");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\n=== 管理员功能 ===\n");
            printf("1. 新增公交线路\n");
            printf("2. 修改公交线路\n");
            printf("3. 删除线路中的站点\n");
            printf("4. 增加站点到线路\n");
            printf("5. 返回主菜单\n");
            printf("请输入选择：");
            scanf("%d", &sub_choice);
            
            switch (sub_choice) {
                case 1: add_bus_route(); break;
                case 2: modify_bus_route(); break;
                case 3: delete_station_from_route(); break;
                case 4: add_station_to_route(); break;
                case 5: break;
                default: printf("无效选择！\n");
            }
        } else if (choice == 2) {
            printf("\n=== 学生功能 ===\n");
            printf("1. 查询站点经过的公交线路\n");
            printf("2. 显示所有公交路线\n");
            printf("3. 最短时间路线规划\n");
            printf("4. 最少换乘路线规划\n");
            printf("5. 从五棵松出发的最短路线\n");
            printf("6. 返回主菜单\n");
            printf("请输入选择：");
            scanf("%d", &sub_choice);
            
            switch (sub_choice) {
                case 1: query_station_routes(); break;
                case 2: display_all_routes(); break;
                case 3: plan_route(0); break;
                case 4: plan_route(1); break;
                case 5: plan_route(2); break;
                case 6: break;
                default: printf("无效选择！\n");
            }
        } else if (choice == 3) {
            printf("感谢使用本系统！\n");
            break;
        } else {
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
