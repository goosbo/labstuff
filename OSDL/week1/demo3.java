package week1;

class Car{
    String color;
    int weight;

    void drive(){
        System.out.println("my car color is "+color);
    }
}

public class demo3{
    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.color = "Red";
        myCar.weight = 1000;
        myCar.drive();
    }
}
