package week2.HotelBilling;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double tariff, serviceCharges;
        int numDay;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter tariff: ");
        tariff = scanner.nextDouble();
        System.out.println("Enter no. of days: ");
        numDay = scanner.nextInt();
        System.out.println("Enter service charges: ");
        serviceCharges = scanner.nextDouble();

        Double _tariff = tariff;
        Integer _numDay = numDay;
        Double _serviceCharges = serviceCharges;

        double tariff_ = _tariff;
        int numDay_ = _numDay;
        double serviceCharges_ = _serviceCharges;
        double total = tariff_ * numDay_ + serviceCharges_;

        System.out.println("Final Hotel Bill: "+total);
        scanner.close();
    }
}
