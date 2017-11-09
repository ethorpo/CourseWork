package ac.uk.napier.set07110Coursework;

import weather.WeatherData;

/**
 * QUESTION 05
 * 
 * If you decide to answer question 05 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer05 {
	public static void main(String[] args) {
		System.out.println("Question 05");
		/*
		 * Add your code below
		 */
		
		String[] weatherData = WeatherData.getData();
		double latitude = 0;
		String [] station = new String[100];
		for (int i = 1; i < weatherData.length - 1; i++) 
		{
			String [] tmpA = weatherData[i].split(",");
			Double hight = Double.parseDouble(tmpA[2]);
			if (hight > latitude)
			{
				station = weatherData[i].split(",");
				latitude = hight;
			}
		}
		System.out.println(station[0] + ", " + station[1] + ", " + station[2] + ", " + station [3]);
	}	
}
