package week1.RoomAbstract;

interface Amenities{
    public void provideWifi();
    public void provideBreakfast();
    public void provideAircon();
    public void providePremiumFeatures();
}

abstract class Room implements Amenities{
    int roomNum;
    double basePrice;

    public Room(int rnum, double price) {
        roomNum = rnum;
        basePrice = price;
    }

    public abstract double calculateTariff();

    public void displayRoomDetails(){
        System.out.println("Room Number: "+roomNum);
        System.out.println("Base Price: "+basePrice);
    }
}

class StandardRoom extends Room{
    boolean wifi, breakfast,aircon;

    public StandardRoom(int rnum, double price) {
        super(rnum, price);
    }

    @Override
    public void provideWifi(){
        wifi = true;
    }

    @Override
    public void provideBreakfast(){
        breakfast = true;
    }

    @Override
    public void provideAircon(){
        aircon = true;
    }

    @Override
    public void providePremiumFeatures() {
        System.out.println("Premium features not supported for standard room");
    }

    @Override
    public double calculateTariff(){
        double tariff = basePrice;
        if(wifi) tariff += 1000;
        if(breakfast) tariff += 5000;
        if(aircon) tariff += 2500;
        return tariff;
    }

    @Override
    public void displayRoomDetails(){
        super.displayRoomDetails();
        System.out.println("Wifi Available: "+wifi);
        System.out.println("Breakfast Available: "+breakfast);
        System.out.println("Aircon Available: "+aircon);
    }
}

class LuxuryRoom extends Room{
    boolean wifi, breakfast,aircon,premium;

    public LuxuryRoom(int rnum, double price) {
        super(rnum, price);
    }

    @Override
    public void provideWifi(){
        wifi = true;
    }

    @Override
    public void provideBreakfast(){
        breakfast = true;
    }

    @Override
    public void provideAircon(){
        aircon = true;
    }

    @Override
    public void providePremiumFeatures(){
        premium = true;
    }

    @Override
    public double calculateTariff(){
        double tariff = basePrice*1.25;
        if(wifi) tariff += 1000;
        if(breakfast) tariff += 5000;
        if(aircon) tariff += 2500;
        if(premium) tariff += 10000;
        return tariff;
    }

    @Override
    public void displayRoomDetails(){
        super.displayRoomDetails();
        System.out.println("Wifi Available: "+wifi);
        System.out.println("Breakfast Available: "+breakfast);
        System.out.println("Aircon Available: "+aircon);
        System.out.println("Premium Features Available: "+premium);
    }
}

public class Main {
    public static void main(String[] args) {
        Room r;
        r = new StandardRoom(43,7500);
        r.provideWifi();
        r.provideAircon();
        System.out.println("Standard room details: ");
        r.displayRoomDetails();
        System.out.println("Calculated tariff: "+r.calculateTariff());

        r = new LuxuryRoom(65, 7500);
        r.provideWifi();
        r.provideAircon();
        r.provideBreakfast();
        r.providePremiumFeatures();
        System.out.println("\nLuxury room details: ");
        r.displayRoomDetails();
        System.out.println("Calculated tariff: "+r.calculateTariff());
    }
}
