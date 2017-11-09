package ac.uk.napier.set07110Coursework;

import java.util.HashSet;

import weather.WeatherData;

/**
 * QUESTION 01
 * 
 * If you decide to answer question 01 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer01 {
	public static void main(String[] args) {
		System.out.println("Question 01");
		/*
		 * Add your code below
		 */

		String[] weatherData = WeatherData.getData();						//Make weatherData usable.
		HashSet<Integer> location = new HashSet<Integer>();					//Store all locations.
		int i = 1;
		while (i < weatherData.length - 1) {								//Test for all Data.
			location.add(Integer.parseInt(weatherData[i].substring(0, 4)));	//Chops Data into parts.
			i++;
		}

		System.out.println("There are " + location.size() + " Sites.");		//Prints number of locations.
	}	
}
