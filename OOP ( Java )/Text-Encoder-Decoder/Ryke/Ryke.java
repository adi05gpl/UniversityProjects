import java.awt.*;
import java.awt.event.*;
import javax.crypto.SecretKey;
import javax.swing.JFrame;
import javax.swing.*;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Map;

public class Ryke extends JFrame implements AESInterface{

    MyTimer t;
    Blowfish bf;
    TripleDES trDes ;
	AES aes ;
    Map<String, Object> keysRSA;
    PrivateKey privateKey ;
    PublicKey publicKey ;

    public Ryke() throws Exception{
		
        initComponents();
        ButtonGroup group = new ButtonGroup();
         group.add(jRadioButton2); 
         group.add(jRadioButton3); 
         group.add(jRadioButton4); 
         group.add(jRadioButton5); 
		  
    }
    private void initComponents() {
		t = new MyTimer();
		 bf = new Blowfish();
		 trDes = new TripleDES();
		 aes = new AES();
		try{
		keysRSA = RSA.getRSAKeys();
		privateKey = (PrivateKey) keysRSA.get("private");
         publicKey = (PublicKey) keysRSA.get("public");
		}
		catch(Exception ex)
		{
		}
        jLabel1 = new JLabel("User Input: ");
        jLabel2 = new JLabel("Encrypted value: ");
	    jLabel3 = new JLabel("Decrypted value: ");  
		jLabel4 = new JLabel("Encryption mode:");
        jRadioButton2 = new JRadioButton();
        jRadioButton3 = new JRadioButton();
        jRadioButton4 = new JRadioButton();
        jRadioButton5 = new JRadioButton();
        jButton1 = new JButton();
	    jLabel5 = new JLabel("Encrypt time: ");
		jLabel6 = new JLabel("Decrypt time: ");
        jTextField4 = new JTextField(5);
        jTextField5 = new JTextField(5);
		jLabel7 = new JLabel("ms");
		jLabel8 = new JLabel("ms");
        jTextField2 = new JTextField();
        jTextField3 = new JTextField();
        jTextField1 = new JTextField();
        jButton2 = new JButton();
        jButton3 = new JButton();
		main = new JFrame();
		jPaneluser = new JPanel();
	    jPanelenc = new JPanel();
	    jPaneldec = new JPanel();
	    jPanelradio = new JPanel();
	    jPanelbot = new JPanel();
	    jPaneltime = new JPanel();
	    jPanelsave = new JPanel();
	    jPanelmain = new JPanel();

		
	  jPanelmain.setLayout(new GridLayout(3,4));
	  
	  jPaneluser.setLayout(new FlowLayout());
 	  jPaneluser.add(jLabel1);
	  jTextField1.setPreferredSize(new Dimension(115,50));
      jPaneluser.add(jTextField1);                
	  
	  jPanelmain.add(jPaneluser);
	  

	  jPanelenc.setLayout(new FlowLayout());
      jPanelenc.add(jLabel2);               // "super" Frame adds Label
	  jTextField2.setPreferredSize(new Dimension(115,50));
	  jPanelenc.add(jTextField2);
	  
	  jPanelmain.add(jPanelenc); 
	  
	  jPaneldec.setLayout(new FlowLayout());	
      jPaneldec.add(jLabel3);               
	  jTextField3.setPreferredSize(new Dimension(115,50));
	  jPaneldec.add(jTextField3);
	  
      jPanelmain.add(jPaneldec); 
	  
	  
	  jPanelradio.add(jLabel4);  
	  jRadioButton2.setText("AES");
	  jPanelradio.add(jRadioButton2);
	  jRadioButton3.setText("Blowfish");
	  jPanelradio.add(jRadioButton3);
	  jRadioButton4.setText("TripleDES");
	  jPanelradio.add(jRadioButton4);  
	  jRadioButton5.setText("RSA");
	  jPanelradio.add(jRadioButton5);
	  
	  jPanelmain.add(jPanelradio);
	  
	  jPanelbot.setLayout(new FlowLayout());
	  jButton1.setText("ENCRYPT");
	  jPanelbot.add(jButton1);	  
	  jButton2.setText("DECRYPT");
	  jPanelbot.add(jButton2);
	  
	  jPanelmain.add(jPanelbot);

	  jPaneltime.setLayout(new FlowLayout());  
	  jPaneltime.add(jLabel5);  
      jPaneltime.add(jTextField4);
	  jPaneltime.add(jLabel7);
	  
	  jPaneltime.add(jLabel6);
      jPaneltime.add(jTextField5); 	  
	  jPaneltime.add(jLabel8);
	  
	  jPanelmain.add(jPaneltime);
	  
	  jPanelsave.setLayout(new FlowLayout());
	  jButton3.setText("Save Key");
	  jPanelsave.add(jButton3);
	  jPanelmain.add(jPanelsave);
	  
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPanelenc);
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPaneldec);
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPanelradio);
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPanelbot);
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPaneltime);
	  jPanelmain.add(new JPanel());
	  jPanelmain.add(jPanelsave);
	  
	  main.add(jPanelmain);
	  main.setTitle("Ryke");  // "super" Frame sets title
      main.setSize(600,450);  // "super" Frame sets initial window size
      main.setVisible(true);   // "super" Frame shows
	  main.setLocationRelativeTo(null);
	  main.setResizable(false);
		
        jRadioButton2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jRadioButton2ActionPerformed(evt);
            }
        });

        jRadioButton3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jRadioButton3ActionPerformed(evt);
            }
        });

        jRadioButton4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jRadioButton4ActionPerformed(evt);
            }
        });

        jRadioButton5.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jRadioButton5ActionPerformed(evt);
            }
        });

        jButton1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jTextField4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jTextField4ActionPerformed(evt);
            }
        });

        jTextField5.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jTextField5ActionPerformed(evt);
            }
        });


        jTextField2.setToolTipText("");
        jTextField2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jTextField2ActionPerformed(evt);
            }
        });

        jTextField3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jTextField3ActionPerformed(evt);
            }
        });

        jTextField1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jTextField1ActionPerformed(evt);
            }
        });

        jButton2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

      	main.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }                      

    private void jRadioButton2ActionPerformed(ActionEvent evt) {                                                      
    }                                             

    private void jRadioButton3ActionPerformed(ActionEvent evt) {                                              
    }                                             

    private void jRadioButton4ActionPerformed(ActionEvent evt) {                                                          
    }                                             

    private void jRadioButton5ActionPerformed(ActionEvent evt) {                                              
    }                                             

    private void jTextField5ActionPerformed(ActionEvent evt) {                                                    
    }                                           

    private void jTextField4ActionPerformed(ActionEvent evt) {                                                    
    }                                           

    private void jButton1ActionPerformed(ActionEvent evt) {                                          
        String message1 = "Please fill in User Input!";
        String message = "Please select an encryption method !";
        if(jTextField1.getText().trim().isEmpty())
            JOptionPane.showMessageDialog(new JFrame(), message1, "Error!", JOptionPane.ERROR_MESSAGE);
     else if(jRadioButton2.getText().trim().isEmpty() || jRadioButton3.getText().trim().isEmpty() || jRadioButton4.getText().trim().isEmpty() || jRadioButton5.getText().trim().isEmpty())
            JOptionPane.showMessageDialog(new JFrame(), message, "Error!", JOptionPane.ERROR_MESSAGE);
        if(jRadioButton2.isSelected()){  
            try{            
                String text2 = jTextField1.getText();
                t.start();
                String encryptedString = aes.encrypt(text2, secretKey) ;
                t.stop();
                jTextField2.setText(String.valueOf(encryptedString));
                jTextField4.setText(t.getElapsedTimeSecs());
            } catch (Exception e){
                System.out.println("AES ENCRYPT BUTTON ERROR" + e.toString());
            }
            return;
        }
        else if(jRadioButton3.isSelected()){             
            try {         
                String text3 = jTextField1.getText();
                t.start();
                String ebyte = bf.encrypt(text3);
                t.stop();
                jTextField2.setText(String.valueOf(ebyte)); 
                jTextField4.setText(t.getElapsedTimeSecs());
            } catch (Exception ex) {
                System.out.println("Blowfish ENCRYPT BUTTON ERROR" + ex.toString());
            }
            return;
        }else if(jRadioButton4.isSelected()){    
            try{                        
                String text4 = jTextField1.getText();   
                t.start();
                String enc = trDes.encode(text4);
                t.stop();
                jTextField2.setText(String.valueOf(enc)); 
                jTextField4.setText(t.getElapsedTimeSecs());
            } catch (Exception ex) {
                System.out.println("TripleDES ENCRYPT BUTTON ERROR" + ex.toString());
            }
            return;
        }else if(jRadioButton5.isSelected()){ 
            try {                         
                String text5 = jTextField1.getText();  
                t.start();
                String encrypted = RSA.encrypt(text5, privateKey);
                t.stop();
                jTextField2.setText(String.valueOf(new String(encrypted)));
                jTextField4.setText(t.getElapsedTimeSecs());        
           } catch (Exception ex) {
                System.out.println("RSA ENCRYPT BUTTON ERROR" + ex.toString());
            }
        }
        else JOptionPane.showMessageDialog(new JFrame(), message, "Error!", JOptionPane.ERROR_MESSAGE);              
    }                                        

    private void jTextField2ActionPerformed(ActionEvent evt) {                                            
    }                                           

    private void jTextField3ActionPerformed(ActionEvent evt) {                                            
    }                                           

    private void jTextField1ActionPerformed(ActionEvent evt) { 	
    }                                                                                

    private void jButton2ActionPerformed(ActionEvent evt) {                                         
        do{
            if(jRadioButton2.isSelected()){ 
                try{           
                    String text2 = jTextField2.getText();
                    t.start();
                    String decryptedText = aes.decrypt(text2, secretKey) ; 
                    t.stop();
                    jTextField3.setText(String.valueOf(decryptedText));
                    jTextField5.setText(t.getElapsedTimeSecs());
                } catch (Exception e) {
                    System.out.println("AES DECRYPT BUTTON ERROR" + e.toString());
                }
                return;            
            }else if(jRadioButton3.isSelected()){  
                try{          
                    String text3 = jTextField2.getText();
                    t.start();
                    String dbyte = bf.decrypt(text3);
                    t.stop();
                    jTextField3.setText(String.valueOf(dbyte));
                    jTextField5.setText(t.getElapsedTimeSecs());
                } catch (Exception ex) {
                    System.out.println("Blowfish DECRYPT BUTTON ERROR" + ex.toString());
                }
                return;
            }else if(jRadioButton4.isSelected()){
                try{            

                    String text4 = jTextField2.getText();
                    t.start();
                    String dec = trDes.decode(text4);
                    t.stop();
                    jTextField3.setText(String.valueOf(dec));
                    jTextField5.setText(t.getElapsedTimeSecs());
                } catch (Exception ex){
                    System.out.println("TripleDES DECRYPT BUTTON ERROR" + ex.toString());
                }
                return;
            }else if(jRadioButton5.isSelected()){
                try {       
                    String text5 = jTextField2.getText();
                    t.start();
                    String decrypted = RSA.decrypt(text5, publicKey);
                    t.stop();
                    jTextField3.setText(String.valueOf(new String(decrypted)));
                    jTextField5.setText(t.getElapsedTimeSecs());
                } catch (Exception ex) {
                    System.out.println("RSA DECRYPT BUTTON ERROR" + ex.toString());
                }
            }
        }while(jButton2.isSelected());

    }                                        

    private void jButton3ActionPerformed(ActionEvent evt) {                                         
        try{
             MyFileWriter fw = new MyFileWriter();
             String message1 = "Please fill in User Input!";
             String message = "Please select an encryption method !";
             String message2 = "Please Encrypt / Decrypt the User Input !";
            if(jTextField1.getText().trim().isEmpty())
                    JOptionPane.showMessageDialog(new JFrame(), message1, "Error!", JOptionPane.ERROR_MESSAGE);
            else if( jTextField2.getText().trim().isEmpty() ||jTextField3.getText().trim().isEmpty())
                    JOptionPane.showMessageDialog(new JFrame(), message2, "Error!", JOptionPane.ERROR_MESSAGE);
            else if(jRadioButton2.getText().trim().isEmpty() || jRadioButton3.getText().trim().isEmpty() || jRadioButton4.getText().trim().isEmpty() || jRadioButton5.getText().trim().isEmpty())
                    JOptionPane.showMessageDialog(new JFrame(), message, "Error!", JOptionPane.ERROR_MESSAGE);
                    
             String text1 = jTextField1.getText();
             String text2 = jTextField2.getText();
             String text3 = jTextField3.getText();
            if(jRadioButton2.isSelected() || jRadioButton3.isSelected() || jRadioButton4.isSelected() || jRadioButton5.isSelected()){
                        fw.writeMyFile(text1, text2, text3);
            }
        }catch(Exception e){
           System.out.println("Error Save File Button " +e.toString());
        }
    }                                        

    public static void main(String args[]){
	try{
		new Ryke().setVisible(true);
    }catch(Exception e) 
	{System.out.println("ERROR in MAIN" + e.toString());}
	}

    public JButton jButton1;
    public JButton jButton2;
    private JButton jButton3;
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;
    private JLabel jLabel5;
    private JLabel jLabel6;
    private JLabel jLabel7;
    private JLabel jLabel8;
    public JRadioButton jRadioButton2;
    public JRadioButton jRadioButton3;
    public JRadioButton jRadioButton4;
    public JRadioButton jRadioButton5;
    public JTextField jTextField1;
    public JTextField jTextField2;
    public JTextField jTextField3;
    public JTextField jTextField4;
    public JTextField jTextField5;
	public JPanel jPaneluser;
	public JPanel jPanelenc;
	public JPanel jPaneldec;
	public JPanel jPanelradio;
	public JPanel jPanelbot;
	public JPanel jPaneltime;
	public JPanel jPanelsave;
	public JPanel jPanelmain;
	public JFrame main;
}