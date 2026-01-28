package week4;

class Buffer {
    private int data;
    private boolean available = false;
    // Method to produce data
    synchronized void produce(int value) {
        while (available) {
            try {
                wait(); // Wait if buffer is full
            } 
            catch (InterruptedException e) {
                System.out.println("Producer interrupted");
            }
        }
        data = value;
        available = true;
        System.out.println("Produced: " + data);
        notify(); // Notify consumer
    }
    // Method to consume data
    synchronized int consume() {
        while (!available) {
            try {
                wait(); // Wait if buffer is empty
            } catch (InterruptedException e) {
                System.out.println("Consumer interrupted");
            }
        }
        available = false;
        System.out.println("Consumed: " + data);
        notify(); // Notify producer
        return data;
    }
}

// Producer thread
class Producer extends Thread {
    private Buffer buffer;
    Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            buffer.produce(i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println("Producer sleep interrupted");
            }
        }
    }
}
// Consumer thread
class Consumer extends Thread {
    private Buffer buffer;
    Consumer(Buffer buffer) {
        this.buffer = buffer;
    }
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            buffer.consume();
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println("Consumer sleep interrupted");
            }
        }
    }
}
// Main class
public class ProducerConsumerDemo {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();
        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);
        producer.start();
        consumer.start();
    }
}
