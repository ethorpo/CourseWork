package ac.uk.napier.set07110Coursework;

import weather.WeatherData;

/**
 * QUESTION 02
 * 
 * If you decide to answer question 02 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer02 {
	public static void main(String[] args) {
		System.out.println("Question 02");
		/*
		 * Add your code below
		 */
		
		String[] weatherData = WeatherData.getData();
		double cold = 1000000;
		String [] station = new String[100];
		for (int i = 1; i < weatherData.length - 1; i++) 
		{
			String [] tmpA = weatherData[i].split(",");
			Double temp = Double.parseDouble(tmpA[9]);
			if (temp < cold)
			{
				station = weatherData[i].split(",");
				cold = temp;
			}
		}
		System.out.println(station[0] + ", " + station[1] + ", " + station[9] + ", " + station [4] + 
				", " + station [5] + ", " + station [6] + ", " + station [7]);
	}
	
}