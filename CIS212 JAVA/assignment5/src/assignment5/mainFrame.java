fpackage assignment5;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;





public class mainFrame extends JFrame {
	JButton selectionButton, mergeButton;
	private JLabel mergePrint, selectionPrint;
	
	//#5
	public mainFrame(ArrayList<tracker> list){
		super("Assignment 5");
		setLayout(new BorderLayout());
		setPreferredSize(new Dimension(300, 150));
		mergePrint = new JLabel();
		selectionPrint = new JLabel();
	
		selectionButton = new JButton("Selection Sort");
		selectionButton.addActionListener(new ActionListener() {
			//#7
			@Override
			public void actionPerformed(ActionEvent e) {
				Thread t1 = new Thread(){
					public void run(){
						double beforeTime = System.nanoTime();
						phonebook.selectionSort(list);
						double afterTime = System.nanoTime();
						double totalTime = afterTime - beforeTime;
						if (phonebook.trueorFalse(list)){
							selectionPrint.setText(Double.toString(totalTime/1000000000));
						}
						else{
							selectionPrint.setText("Error");
						}
					}	
			};
			t1.start();
			}
	});

		
		mergeButton = new JButton("Merge Sort");
		mergeButton.addActionListener(new ActionListener() {
			//#7
			@Override
			public void actionPerformed(ActionEvent e) {
				Thread t2 = new Thread(){
					public void run(){
						double beforeTime = System.nanoTime();
						phonebook.mergeSort(list);
						double afterTime = System.nanoTime();
						double totalTime = afterTime - beforeTime;
						if (phonebook.trueorFalse(list)){
							mergePrint.setText(Double.toString(totalTime/1000000000));
						}
						else{
							mergePrint.setText("Error");
						}
					}	
			};
			t2.start();
		}
});

		JPanel buttonPanelWest = new JPanel(new GridLayout(2, 2));
		buttonPanelWest.add(selectionButton);
		buttonPanelWest.add(selectionPrint);
		buttonPanelWest.add(mergeButton);
		buttonPanelWest.add(mergePrint);
		add(buttonPanelWest, BorderLayout.WEST);
			}
		}
	
			
