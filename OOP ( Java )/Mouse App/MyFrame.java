import java.awt.Color;
import java.awt.Graphics;
import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class MyFrame implements MouseMotionListener, MouseListener{
		private JFrame f;
		private Graphics g;
		private int r,v,a;
		private int clickCount;
		private boolean pressed= true;
			public void createFrame(){
				f = new JFrame("My Hello Window");;
				f.setSize(500,500);
					
				f.getContentPane().setBackground(Color.WHITE);
				f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				f.addMouseMotionListener(this);
				f.setVisible(true);
				
				clickCount++;
				Random random = new Random();
				r = random.nextInt(200);
				v = random.nextInt(200);
				a = random.nextInt(200);
				
				
			}
			
			public void mouseMoved(MouseEvent e){
				if(clickCount % 2 == 0)
					System.out.println("Click");
				g = f.getGraphics();
				g.setColor(new Color(r,v,a));
				g.fillOval(e.getX(), e.getY(), 10, 10);
			}
				
			public void mouseDragged(MouseEvent e){
			Random rand = new Random();
				r = rand.nextInt(200);
				v = rand.nextInt(200);
				a = rand.nextInt(200);
			if(clickCount % 2 == 0)
					System.out.println("Click");
				g = f.getGraphics();
				g.setColor(new Color(r,v,a));
				g.fillOval(e.getX(), e.getY(), 10, 10);
			}
			public void mousePressed(MouseEvent e){}
			public void mouseReleased(MouseEvent e){}
			public void mouseClicked(MouseEvent e){
			pressed =!pressed ;
			}
			public void mouseEntered(MouseEvent e){}
			public void mouseExited(MouseEvent e){}
		
}