package week4;

class Callme {
    synchronized void call(String msg){
        System.out.print("["+msg);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }
        System.out.print("]");
    }

    public static void main(String[] args) {
        Callme c = new Callme();
        c.call("Random message");
    }
}

class Caller extends Thread{
    Callme c;
    String msg;

    Caller(String msg){
        this.msg = msg;
        c = new Callme();
    }

    @Override
    public void run(){
        c.call(msg);
    }
}

public class CallerDemo{
    public static void main(String[] args) {
        Caller c1 = new Caller("Manipal ");
        Caller c2 = new Caller("Institute ");
        Caller c3 = new Caller("of ");
        Caller c4 = new Caller("Technology ");
        c1.start();
        c2.start();
        c3.start();
        c4.start();
    }
}