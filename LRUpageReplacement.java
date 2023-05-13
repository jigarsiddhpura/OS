// using LinkedList
import java.util.*;

public class LRUpageReplacement {
    public static void main(String[] args) {
        int[] pageRequests = { 1, 2, 1, 0, 3, 0, 4, 2, 4};
        int numPageFrames = 3;

        LinkedList<Integer> pageFrames = new LinkedList<>();
        int pageFaults = 0;

        for (int i = 0; i < pageRequests.length; i++) {
            int page = pageRequests[i];

            if (!pageFrames.contains(page)) {
                if (pageFrames.size() < numPageFrames) {
                    pageFrames.addLast(page);
                } else {
                    pageFrames.removeFirst();
                    pageFrames.addLast(page);
                }

                pageFaults++;
            } else {
                pageFrames.removeFirst();
                pageFrames.addLast(page);
            }
            System.out.println(pageFrames);
        }

        System.out.println("Page faults: " + pageFaults);
    }
}
