package week2;

enum Apple{
    Jonathan, GoldenDel, RedDel, Winesap, Cortland
}

public class EnumDemo {
    public static void main(String[] args) {
        Apple ap = Apple.RedDel;
        System.out.println("Value of ap: "+ap);
        System.out.println("");
        ap = Apple.GoldenDel;
        if(ap == Apple.GoldenDel)System.out.println("ap contains GoldenDel.\n");

        switch(ap){
            case Jonathan -> System.out.println("Jonathan is red.");
            case GoldenDel -> System.out.println("Golden Delicious is yellow.");
            case RedDel -> System.out.println("Red Delicious is red.");
            case Winesap -> System.out.println("Winesap is red.");
            case Cortland -> System.out.println("Cortland is red.");
        }
    }
}
