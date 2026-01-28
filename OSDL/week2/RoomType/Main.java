package week2.RoomType;

import java.util.Scanner;

enum RoomType{
    STANDARD(3000),DELUXE(4500),SUITE(7000);

    private double baseTariff;

    RoomType(double  tariff){
        baseTariff = tariff;
    }

    public double getBaseTariff(){
        return baseTariff;
    }

    public double getTotalCost(int numDays){
        return baseTariff * numDays;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String type; int ndays;
        System.out.println("Enter type of room(STANDARD, DELUXE, SUITE): ");
        type = scanner.next();

        if(type.compareTo("STANDARD") != 0 && type.compareTo("DELUXE") != 0 && type.compareTo("SUITE") != 0){
            System.out.println("Invalid room type");
            System.exit(0);
        }

        RoomType room = RoomType.valueOf(type);
        System.out.println("Enter no. of days: ");
        ndays = scanner.nextInt();

        System.out.println("Base Tariff: "+room.getBaseTariff());
        System.out.println("No. of days: "+ndays);
        System.out.println("Total Cost: "+room.getTotalCost(ndays));
        scanner.close();
    }
}
 