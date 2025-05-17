import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]); // 요청 시간 기준 정렬

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]); // 소요 시간 기준 정렬
        int time = 0; // 현재 시각
        int idx = 0;  // jobs 배열 인덱스
        int total = 0; // 총 대기시간
        int count = 0;

        while (count < jobs.length) {
            // 현재 시간까지 들어온 작업들을 PQ에 넣기
            while (idx < jobs.length && jobs[idx][0] <= time) {
                pq.offer(jobs[idx]);
                idx++;
            }

            if (!pq.isEmpty()) {
                int[] job = pq.poll();
                time += job[1];
                total += time - job[0]; // 종료 시점 - 요청 시점
                count++;
            } else {
                // 아직 들어온 작업이 없는 경우 → 시간 한 칸 진행
                time = jobs[idx][0];
            }
        }

        return total / jobs.length;
    }
}
