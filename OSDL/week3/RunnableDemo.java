package week3;

class MyTask implements Runnable{
    @Override
    public void run(){
        System.out.println("Thread is running: "+Thread.currentThread().getName());
    }
}

public class RunnableDemo {
    public static void main(String[] args) {
        MyTask task = new MyTask();

        Thread t1 = new Thread(task);
        Thread t2 = new Thread(task);

        t1.start();
        t2.start();
    }
}
