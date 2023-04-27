import java.util.*;

public class bankers {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[][] allocation = {
      { 0, 1, 0 },
      { 2, 0, 0 },
      { 3, 0, 2 },
      { 2, 1, 1 },
      { 0, 0, 2 },
    };
    int[][] claim = {
      { 7, 5, 3 },
      { 3, 2, 2 },
      { 9, 0, 2 },
      { 4, 2, 2 },
      { 5, 3, 3 },
    };
    int[] total_res = { 10, 5, 7 };
    int[] total_alloc = {0,0,0};
    int[] avail = {0,0,0};
    int[][] remaining_need = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    ArrayList<Integer> stateArr = new ArrayList<Integer>();
    
    for (int i = 0; i < allocation.length; i++) {
      for (int j = 0; j < allocation[i].length; j++) {
            total_alloc[j] += allocation[i][j];
            remaining_need[i][j] = claim[i][j] - allocation[i][j];
      }
    }

    for (int i = 0; i < total_res.length; i++) {
      avail[i] = total_res[i] - total_alloc[i];
    }

    int k = remaining_need.length;
    int i = 0;
    while(k!=0){
      if(i==5){
        i = 0;
      }
      // System.out.print("i = "+i+" k = "+k);
      if(remaining_need[i][0] <= avail[0] && remaining_need[i][1] <= avail[1] && remaining_need[i][2] <= avail[2] &&  remaining_need[i][0] != -1){
        stateArr.add(i+1);
        for (int j = 0; j < avail.length; j++) {
          avail[j] += allocation[i][j];
        }
        remaining_need[i][0] = -1;
        k-=1;
        
      }
      i+=1;
    }

    System.out.println("Sequence of resource allocation :");
    for (int e = 0; e < stateArr.size(); e++) {
      System.out.print("P"+stateArr.get(e)+" ");
    }

  }
}
