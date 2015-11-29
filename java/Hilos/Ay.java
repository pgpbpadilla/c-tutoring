public class Ay implements Runnable {

    public void run () {
        for(int i=0; i< 10; i++){
            try {
                Thread.sleep(500);
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
            ay();
        }
    }

    public void ay() {
        System.out.println("Aaaaaaaaaayy!!!!!");
    }

}
