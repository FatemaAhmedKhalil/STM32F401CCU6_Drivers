 u8 debounce(void)
 {
	 u8 Pressed = 0;
	 static u8 count = 0;
	 static u8 LastState = 1;
	 
	 u8 CurrentState = GET_BIT(PINB,0);
	 
	 if (CurrentState != LastState)
	 {
		 count++;
		 if (count >= 4)
		 {
			 LastState = CurrentState;
			 
			 if (CurrentState != 0)
			 Pressed = 1;

			 count = 0;
		 }
	 }
	 
	 else
	 count = 0;  // Reset counter
	 
	 return Pressed;
 }