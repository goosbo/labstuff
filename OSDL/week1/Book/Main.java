package week1.Book;

class Book {
    private int bookID;
    private String bookTitle;
    private String authorName;
    private  double price;
    private boolean available;

    public void setID(int id){
        if(id <= 0){
            System.out.println("Book ID must be positive");
            return;
        }
        bookID = id;
    }

    public void setTitle(String title){
        bookTitle = title;
    }

    public void setAuthor(String author){
        authorName = author;
    }

    public void setPrice(double p){
        if(p <= 0){
            System.out.println("Price must be positive");
            return;
        }
        price = p;
    }

    public void setAvailability(boolean available){
        this.available = available;
    }

    public int getId(){
        return bookID;
    }

    public String getTitle(){
        return bookTitle;
    }

    public String getAuthor(){
        return authorName;
    }

    public double getPrice(){
        return price;
    }

    public boolean getAvailability(){
        return available;
    }
}

public class Main{
    public static void main(String[] args) {
        Book b = new Book();
        b.setID(54);
        b.setTitle("Random Book Title");
        b.setAuthor("Random Author");
        b.setPrice(124.53);
        b.setPrice(-56.4);
        b.setAvailability(true);

        System.out.println("Book ID: "+b.getId());
        System.out.println("Book Title: "+b.getTitle());
        System.out.println("Author Name: "+b.getAuthor());
        System.out.println("Price: "+b.getPrice());
        System.out.println("Book Available: "+b.getAvailability());
    }
}
