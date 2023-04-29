import java.util.*;

public class FIFOpageReplacement {
    public static void main(String[] args) {
        int[] allPageRequests =  {1, 2, 3, 4, 2, 1, 5, 3, 2, 4, 6};
        int numPageFrames = 3;

        Queue<Integer> pageFrames = new LinkedList<>();
        int pageFaults = 0;

        for (int i = 0; i < allPageRequests.length; i++) {
            int page = allPageRequests[i];

            if (!pageFrames.contains(page)) {
                if (pageFrames.size() < numPageFrames) {
                    // .offer similar to .add
                    pageFrames.offer(page);
                } else {
                    // .poll similar to .remove
                    pageFrames.poll();
                    pageFrames.offer(page);
                }

                pageFaults++;
            }
        }

        System.out.println("Page faults: " + pageFaults);
    }
}
