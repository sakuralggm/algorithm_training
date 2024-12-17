public class Dijkstra {
    public int[] findShortestPath(int[][] graph, int start) {
        int n = graph.length;
        int[] distances = new int[n];
        boolean[] visited = new boolean[n];

        // 初始化距离数组
        for (int i = 0; i < n; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        distances[start] = 0;

        // 主循环
        for (int count = 0; count < n - 1; count++) {
            // 找到未访问节点中距离最小的
            int minDistance = Integer.MAX_VALUE;
            int minIndex = -1;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && distances[v] < minDistance) {
                    minDistance = distances[v];
                    minIndex = v;
                }
            }

            // 标记为已访问
            visited[minIndex] = true;

            // 更新相邻节点的距离
            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[minIndex][v] != 0
                        && distances[minIndex] != Integer.MAX_VALUE
                        && distances[minIndex] + graph[minIndex][v] < distances[v]) {
                    distances[v] = distances[minIndex] + graph[minIndex][v];
                }
            }
        }
        return distances;
    }
}
