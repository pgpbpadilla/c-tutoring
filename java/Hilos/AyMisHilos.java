public class AyMisHilos {

    public static void main (String args[]) {
        Thread ay = new Thread(new Ay());
        Thread misHilos = new MisHilos();
        Thread pennyWise = new Thread () {
                public void run () {
                    System.out.println("Todos flotan!!!! Todos flotan!!!!");
                }
            };

        ay.start();
        misHilos.start();
        try{
            Thread.sleep(750);
        }catch (Exception e) {
            System.out.println(e.getMessage());
        }
        pennyWise.start();
    }

}
