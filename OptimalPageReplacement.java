import java.util.*;

public class OptimalPageReplacement {
    public static void main(String[] args) {
        int[] allPageRequests = {1, 2, 3, 4, 2, 1, 5, 3, 2, 4, 6};
        int numPageFrames = 3;

        ArrayList<Integer> pageFrames = new ArrayList<Integer>();
        int pageFaults = 0;

        for (int i = 0; i < allPageRequests.length; i++) {
            int page = allPageRequests[i];

            if (!pageFrames.contains(page)) {
                // empty frame check
                if (pageFrames.size() < numPageFrames) {
                    pageFrames.add(page);
                } else {
                    int indexToReplace = findPageToReplace(allPageRequests, i, pageFrames);
                    pageFrames.set(indexToReplace, page);
                }
                pageFaults++;
            }
        }
        System.out.println("Page faults: " + pageFaults);
    }

    private static int findPageToReplace(int[] allPageRequests, int currentIndex, List<Integer> pageFrames) {
        int indexToReplace = -1;
        int futurePageCount = 0;
        ArrayList<Integer> futurePageIndexes = new ArrayList<Integer>();

        for (int i = currentIndex+1 ; i < allPageRequests.length; i++) {
            if(futurePageCount<pageFrames.size()){
                int pgRequest = allPageRequests[i];
                for (int j = 0; j < pageFrames.size(); j++) {
                    int page = pageFrames.get(j);
                    if(page == pgRequest){
                        futurePageIndexes.add(j);
                        indexToReplace = j;
                        futurePageCount++;
                        break;
                    }
                }
            }
        }

        if(indexToReplace==-1){
            indexToReplace = 0;
        }
        else if(futurePageCount<pageFrames.size()){
            for (int j = 0; j < pageFrames.size(); j++) {
                if(!futurePageIndexes.contains(j)){
                    indexToReplace = j;
                    break;
                }
            }
        }
        return indexToReplace;
    }
}
