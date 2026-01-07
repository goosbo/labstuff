package week1.Room;

class Room{
    private int roomNum;
    private String type;
    private double basePrice;

    Room(int roomNum, double basePrice){
        this.roomNum = roomNum;
        this.basePrice = basePrice;
        this.type = "None";
    }

    Room(int roomNum,String type,double basePrice){
        this.roomNum = roomNum;
        this.type = type;
        this.basePrice = basePrice;
    }

    public void display(){
        System.out.println("Room Number: "+roomNum);
        System.out.println("Room Type: "+type);
        System.err.println("Base Price: "+basePrice);
    }
}

class DeluxeRoom extends Room{
    private boolean wifiAvailable;
    private boolean compBreakfast;

    public DeluxeRoom(int roomNum, double basePrice, boolean  wifiAvailable, boolean compBreakfast) {
        super(roomNum, basePrice);
        this.wifiAvailable = wifiAvailable;
        this.compBreakfast = compBreakfast;
    }

    public DeluxeRoom(int roomNum, String type, double basePrice, boolean  wifiAvailable, boolean compBreakfast) {
        super(roomNum, type, basePrice);
        this.wifiAvailable = wifiAvailable;
        this.compBreakfast = compBreakfast;
    }

    @Override
    public void display(){
        super.display();
        System.out.println("Wifi Available: "+wifiAvailable);
        System.out.println("Complimentary Breakfast: "+compBreakfast);
    }
    
}

public class Main {
    public static void main(String[] args) {
        Room r1 = new Room(12,10000);
        System.out.println("Room 1 details");
        r1.display();
        Room r2 = new Room(15,"suite",17500.5);
        System.out.println("\nRoom 2 details");
        r2.display();

        DeluxeRoom d1 = new DeluxeRoom(30, 34000,true, false);
        System.out.println("\nDeluxe Room 1 details");
        d1.display();
        System.out.println("\nDeluxe Room 2 details");
        DeluxeRoom d2 = new DeluxeRoom(43,"suite", 42000, true, true);
        d2.display();
    }
    
}
