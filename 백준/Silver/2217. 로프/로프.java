import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int minNum;
    int maxNum;
    int maxWeight=0;

    List<Integer> rope = new ArrayList<>();

    for(int i = 1; i <= n; i++) {
      int weight = sc.nextInt();
      rope.add(weight);
    }

    rope.sort(Comparator.naturalOrder());
    maxNum = Collections.max(rope);

    while(!rope.isEmpty()) {
      minNum = rope.get(0);
      maxWeight = minNum * rope.size();

      rope.remove(0);

      if (maxWeight > maxNum ) maxNum = maxWeight;
    }


    System.out.println(maxNum);

  }
}