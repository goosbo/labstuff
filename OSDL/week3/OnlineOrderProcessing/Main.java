package week3.OnlineOrderProcessing;
import java.util.Random;

class OrderValidation extends Thread{
    
    int ordernum;

    public OrderValidation(int n) {
        ordernum = n;
    }
    
    @Override
    public void run(){
        System.out.println("Starting validation of order #"+ordernum);
        System.out.println("Order #"+ordernum+" validation progress: 0%");
        Random r = new Random();
        int totalProgress = 0;
        while(true){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Order #"+ordernum+" validation interrupted!");
            }
            totalProgress += Math.abs(r.nextInt())%30;
            if(totalProgress > 100)break;
            System.out.println("Order #"+ordernum+" validation progress: "+totalProgress+"%");
        }
        System.out.println("Completed Order #"+ordernum+" validation!");
    }
}

class PaymentProcessing extends Thread{
    
    int paymentnum;

    public PaymentProcessing(int n) {
        paymentnum = n;
    }
    
    @Override
    public void run(){
        System.out.println("Starting procession of payment #"+paymentnum);
        System.out.println("Payment #"+paymentnum+" processing progress: 0%");
        Random r = new Random();
        int totalProgress = 0;
        while(true){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Payment #"+paymentnum+" procession interrupted!");
            }
            totalProgress += Math.abs(r.nextInt())%30;
            if(totalProgress > 100)break;
            System.out.println("Payment #"+paymentnum+" procession progress: "+totalProgress+"%");
        }
        System.out.println("Completed Payment #"+paymentnum+" processing!");
    }
}

class OrderShipment extends Thread{
    
    int ordernum;

    public OrderShipment(int n) {
        ordernum = n;
    }
    
    @Override
    public void run(){
        System.out.println("Starting shipment of order #"+ordernum);
        System.out.println("Order #"+ordernum+" shipment progress: 0%");
        Random r = new Random();
        int totalProgress = 0;
        while(true){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Order #"+ordernum+" shipment interrupted!");
            }
            totalProgress += Math.abs(r.nextInt())%30;
            if(totalProgress > 100)break;
            System.out.println("Order #"+ordernum+" shipment progress: "+totalProgress+"%");
        }
        System.out.println("Completed Order #"+ordernum+" shipped!");
    }
}

public class Main {
    public static void main(String[] args) {
        OrderValidation v1 = new OrderValidation(6742);
        PaymentProcessing p1 = new PaymentProcessing(7213);
        OrderShipment o1 = new OrderShipment(9833);

        v1.start();
        o1.start();
        p1.start();
    }
}
