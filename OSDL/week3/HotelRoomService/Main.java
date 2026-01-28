package week3.HotelRoomService;

class RoomCleaning extends Thread{

    int roomno;

    public RoomCleaning(int rn) {
        roomno = rn;
    }

    @Override
    public void run(){
        
        for(int i = 0; i < 100;i+=20){
            try {
                System.out.println("Cleaning room Room no. "+roomno+". Progress: "+i+"%");
                sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Cleaning of room Room no. "+roomno+" interrupted!");
            }
        }
        
        System.out.println("Cleaning of Room no. "+roomno+" completed!");
    }
}

class FoodDelivery extends Thread{

    int roomno;

    public FoodDelivery(int rn) {
        roomno = rn;
    }

    @Override
    public void run(){
        
        for(int i = 0; i < 100; i+=20){
            try {
                System.out.println("Delivering food to Room no. "+roomno+". Progress: "+i+"%");
                sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Delivery of food to Room no. "+roomno+" interrupted!");
            }
        }
        
        System.out.println("Food Delivery to Room no. "+roomno+" completed!");
    }
    
}

class Maintenance extends Thread{

    int roomno;

    public Maintenance(int rn) {
        roomno = rn;
    }

    @Override
    public void run(){
        for(int i = 0; i < 100; i+= 20){
            
            try {
                System.out.println("Maintenance of Room no. "+roomno+" in progess. Progress: "+i+"%");
                sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Maintenance of Room no. "+roomno+" interrupted!");
            }
        }
        
        System.out.println("Maintenance of Room no. "+roomno+" completed!");
    }
}

public class Main {
    public static void main(String[] args) {
        RoomCleaning r1 = new RoomCleaning(404);
        FoodDelivery f1 = new FoodDelivery(132);
        Maintenance m1 = new Maintenance(312);

        r1.start();
        f1.start();
        m1.start();

    }
}
