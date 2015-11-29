public class MisHilos extends Thread {

    public void run() {
        for(int i=1; i<=10; i++){
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
            misHilos();
        }
    }
    
    public void misHilos() {
        System.out.println(".... mis hilooooooosssss!");
    }

}
