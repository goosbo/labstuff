package week1;

class Student{
    private int id;
    private String name;

    public void setId(int id){
        this.id = id;
    }

    public void setName(String name){
        this.name = name;
    }

    int getId(){
        return id;
    }

    String getName(){
        return name;
    }
}

public class Demo {
    public static void main(String[] args) {
        Student s = new Student();
        s.setId(101);
        s.setName("Ahamed");
        System.out.println("ID: "+s.getId());
        System.out.println("Name: "+s.getName());
    }
}
