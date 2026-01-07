package week1.Hotel;

class Room{
    int roomnum;
    double baseTariff;

    Room(int rnum,double btariff){
        roomnum = rnum;
        baseTariff = btariff;
    }

    public double calculateTariff(){
        return baseTariff;
    }

    public void display(){
        System.out.println("Room Num: "+roomnum);
        System.out.println("Base Tariff: "+baseTariff);
    }
}

class StandardRoom extends Room{
    private boolean airConditioning;
    private boolean additionalAmenities;

    public StandardRoom(int rnum, double btariff, boolean aircon, boolean additional) {
        super(rnum, btariff);
        airConditioning = aircon;
        additionalAmenities = additional;
    }

    @Override
    public double calculateTariff(){
        double tariff = baseTariff;
        if(airConditioning)tariff += 2500;
        if(additionalAmenities)tariff += 5000;
        return tariff;
    }

    @Override
    public void display(){
        super.display();
        System.out.println("Air Conditioning: "+airConditioning);
        System.out.println("Additonal Amenities: "+additionalAmenities);
    }
}

class LuxuryRoom extends Room{
    private boolean airConditioning;
    private boolean additionalAmenities;
    private boolean premiumFeatures;

    public LuxuryRoom(int rnum, double btariff, boolean aircon, boolean additional,boolean premium) {
        super(rnum,btariff);
        airConditioning = aircon;
        additionalAmenities = additional;
        premiumFeatures = premium;
    }

    @Override
    public double calculateTariff(){
        double tariff = baseTariff;
        if(airConditioning)tariff += 2500;
        if(additionalAmenities)tariff += 5000;
        if(premiumFeatures) tariff += 10000;
        return tariff;
    }

    @Override
    public void display(){
        super.display();
        System.out.println("Air Conditioning: "+airConditioning);
        System.out.println("Additonal Amenities: "+additionalAmenities);
        System.out.println("Premium Features: "+premiumFeatures);
    }
}

public class Main {
    public static void main(String[] args) {
        Room r;
        r = new StandardRoom(34,10000,true,false);
        r.display();
        System.out.println("Standard room tariff: "+r.calculateTariff());
        r = new LuxuryRoom(45, 15000, true, true, true);
        r.display();
        System.out.println("Luxury room tariff: "+r.calculateTariff());
    }
}
