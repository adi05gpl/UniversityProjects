import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;
import java.io.*;
import java.text.SimpleDateFormat;


public class Persoana{
	private String _Username,_Password;
	public Persoana(String Username, String Password){
		_Username = Username;
		_Password = Password;
	}
	public void setUsername(String Username){
		this._Username = Username;
	}
	public void setPassword(String Password){
		this._Password = Password;
	}
}