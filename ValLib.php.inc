<?php
	/* This function removes any non-numeric characters  
	   and ensures that the resulting int is of a size
	   that could be a correct phone number.
	*/
	function isPhoneNumber($number){
		$number = filter_var($number, FILTER_SANITIZE_NUMBER_INT); 
		/*Fancy regex cleans out any non numeric characters*/
		$number = preg_replace('/[^0-9]/', '', $number);
		if (strlen($number) < 10){
			return FALSE;
		} elseif (strlen($number) > 14) {
			return FALSE;
		}
		else {
			return TRUE;
		}
	}
	/* This one isn't really reusable or interesting.
	   All it does is ensure that the drop-down to
	   select call time hasn't been tampered with.
	*/
	function isValidTime($time){
		/*If time is less than 1 minute or more
		  than 30, block it.*/
		if ($time < 1){
			return FALSE;
		} elseif ($time > 30){
			return FALSE;
		/*If time is 5 or less min, ensure it is
		a whole number*/
		} elseif ($time <= 5 && (fmod($time, 1) == 0.0)){
			return TRUE;
		/*If time is < 30 min && > 5 min, make sure
		it's divisible by 5. */
		} elseif (($time <= 30) && (fmod($time, 5) == 0.0)){
			return TRUE;
		/*I can think of no case in which you get 
		this far down.*/
		} else {
			return FALSE;
		}	
	
	}
?>
