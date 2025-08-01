# [Silver III] 기숙사 서바이벌 (Dormvival Games) - 16131 

[문제 링크](https://www.acmicpc.net/problem/16131) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 7월 15일 01:41:20

### 문제 설명

<p>서울 S 과학고의 기숙사는 매우 특이한 체계를 가지기로 유명하다. 기숙사에는 수많은 방이 있고, 각각의 방에는 번호가 붙어져 있어 번호가 작을수록 더 좋은 질의 방을 갖게 된다. 이 기숙사의 운영부는 상점과 벌점이라는 것을 학생들에게 주지만, 어떤 과학고의 체계와는 달리 벌점 누적에 의한 퇴사 제도가 없다. 따라서 기숙사 운영부에서는 매주 각 학생의 상점과 벌점에 따라 학생들의 방을 재배정하게 된다. 1번 방과 가까운 최상의 방들은 상태가 매우 좋아 학생들이 바라지만, 끝번과 가까운 최하의 방들은 방의 상태가 처참해 학생들이 피하려고 한다.</p>

<p>기숙사 운영부는 처음 방 배정을 학번을 기반으로 배정하였는데, 학생들에게는 <em>1</em>번에서 <em>N</em>번의 학번이 주어지고 첫 주는 그 번호대로 방에 들어가게 된다. <em>1</em>번인 홍 군과 홍 군의 친한 친구 조 군은 첫 주에 각각 <em>1</em>번 방과 <em>A</em>번 방에 배정되었다. 홍 군은 조 군과 같이 있기를 원했고, 두 학생의 방 번호의 차이가 <em>B</em> 이하이면 홍 군은 그 주에 기분이 좋아진다고 한다. 주어진 기간 <em>M</em>주 동안 학생들은 기숙사에서 지내게 되고, 마지막 주에는 상점과 벌점을 주지 않는다. 즉, <em>M-1</em>주 동안만 상점과 벌점을 기록한다.</p>

<p>M주 동안 홍 군의 기분이 좋은 주는 총 몇 주인지 알아내고, 홍 군이 최대 몇 주 동안 연속으로 기분이 좋은지도 알아내시오.</p>

<ul>
	<li>방의 교환
	<ol>
		<li>두 방의 교환이라는 것은, 2개의 방 각각의 사람을 서로 바꾸는 것을 의미한다.</li>
		<li>방은 최고의 방에서 시작해서 최악의 방까지 순서대로 순위 상 인접한 두 방만 교환한다. 즉, 처음에 1, 2번 방을 확인하고, 다음에는 2, 3번, 마지막으로 <em>N-1</em>번과 <em>N</em>번 방의 상/벌점을 확인한다.</li>
		<li>방의 교환 기준인 상, 벌점은 방을 바꾸기 전 주에 받은 것으로만 확인한다. 즉 상점과 벌점은 매주 초기화된다.</li>
	</ol>
	</li>
	<li>방의 교환 조건. 두 방의 교환이 일어나기 위한 조건은 다음과 같다. 이때, 점수는 상점-벌점의 값이다.
	<ol>
		<li>두 방의 학생의 점수가 모두 0 이상인 경우, 나쁜 방의 학생의 점수가 좋은 방의 학생의 점수보다 2점 이상 높다면 두 방을 교환한다.</li>
		<li>좋은 방의 학생의 점수가 0 이상이고 나쁜 방의 학생의 점수가 음수이면 방을 바꾸지 않는다.</li>
		<li>나쁜 방의 학생의 점수가 0 이상이고 좋은 방의 학생의 점수가 음수이면 방을 바꾼다.</li>
		<li>두 방의 학생의 점수가 모두 음수인 경우, 나쁜 방의 학생의 점수가 좋은 방의 학생의 점수보다 4점 이상 높다면 두 방을 교환한다.</li>
		<li>만약 방이 교체된다면, 방이 좋아진 사람에게는 -2점이, 나빠진 사람에게는 +2점이 부여되어 방 번호의 급격한 변동을 방지한다.</li>
	</ol>
	</li>
</ul>

### 입력 

 <p>첫 줄에는 전체 학생 수 <em>N</em> (10 ≤ <em>N</em> ≤ 100), 조 군의 방 번호 <em>A</em> (1 <<em> A</em> ≤ <em>N</em>), 기분이 좋은 값 <em>B </em>(1 ≤ <em>B</em> ≤ 50), 기숙사 생활의 기간(주 단위) <em>M</em> (1 ≤ <em>M</em> ≤ 50)이 차례로 한 칸씩 공백을 두고 주어진다.  </p>

<p>두 번째 줄부터 <em>M</em>-1개의 줄에 주간의 상벌점 정보가 주어진다. 주마다 차례대로 각 학생의 학번 순서대로 상점 <em>N</em>개가 한 줄에 주어지고, 벌점 <em>N</em>개가 한 줄에 주어진다. 상벌점은 0보다 크거나 같고 100보다 작은 정수이다.</p>

### 출력 

 <p>첫 줄에 ‘홍 군의 기분이 좋은 주의 수’와 ‘연속으로 기분이 좋은 기간의 최댓값’을 공백으로 분리하여 출력한다. 한 주도 기분이 좋지 않으면 ‘연속으로 기분이 좋은 기간의 최댓값’은 0으로 정의한다.</p>

