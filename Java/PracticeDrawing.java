

public class PracticeDrawing {
  
  public static void main( String[]args){
    drawNode(.5, .5, "A");
    private static Final double DELTAY;
    private double deltax; 
    private int nodeNumber = 0;
  }
  public static void drawNode(double x, double y, String letter){
    StdDraw.setPenColor(StdDraw.LIGHT_GRAY);
    StdDraw.filledCircle(x, y, 0.025);
    StdDraw.setPenColor(StdDraw.BLACK);
    StdDraw.circle(x, y, .025);
    StdDraw.text(x, y, letter);
  
  }
  
  public void draw(){
    deltax = .925 / (size()-1);
    setCoords();
    drawLines();
    drawNodes();
  }
 
  private void drawNodes(){
  }
  
  private void drawLines(){
  }
  
  private void setCoords(Node node, double yCoord){
    if( node == null){
      returnl
    }
    setCoords(node.left, yCoord - DELTAY);
    node.xCoord = DELTAX * nodeNumber;
    nodenumber++;
    node.yCoord = yCoord;
    setCoords(node.right, yCoord - DELTAY);
  
    public static void draw1(){
    StdDraw.setPenRadius(0.05);
    StdDraw.setColor(StdDraw.BLUE);
    StdDraw.point(0.5, 0.5,);
    
    StdDraw.setColor(StdDraw.RED);
    StdDraw.line(.25, .25, .75, .75);
    
    StdDraw.setPenRadius(0.01);
    StdDraw.setColor(StdDraw.GREEN);
    StdDraw.circle(.5, .5, .125);
    
    StdDraw.setColor(StdDraw.BLACK);
    StdDraw.square(.5, .5, .125);
    
    StdDraw.setColor(StdDraw.PINK);
    StdDraw.arc(.5, .5, 0.0, 180.0);
    
    StdDraw.setColor(StdDraw.ORAGNE);
}
                              