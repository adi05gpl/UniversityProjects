public class MyTimer{
    
    private long startTime = 0;
    private long stopTime = 0;
    private boolean running = false;
        
    public void MyTimer()
    {
        
    }
    public void start(){
        this.startTime = System.currentTimeMillis();
        this.running = true;
    }
    public void stop(){
        this.stopTime = System.currentTimeMillis();
        this.running = false;
    }
    
    public String getElapsedTimeSecs(){
        long elapsed;
            elapsed = (stopTime - startTime);
        return String.valueOf(elapsed);
    }
    
}
