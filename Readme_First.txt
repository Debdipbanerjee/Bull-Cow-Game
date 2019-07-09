1.Name:	Bulls&Cows
2.Developer: Debdip Banerjee
3.Date: 23rd January,2019 - 3rd March
4.Type:	Word Based Guessing Game

5.Requirements:
		Windows:  
			1.Please Use Visual Studio Community 2018 Or Higher
			2.Main.cpp, FBullCowGame.h, FBullCowGame.cpp
				add These 3 Files Under Same Project
			3.Run From Main.cpp
			4.If You Use Dev Cpp or Code::Blocks Please Change Unreal Standards
				Or For Sake of Simplicity, Just Use VS Community 2018 Or Higher
		
		   Mac:
			1.Please Use XCODE
			2.Main.cpp, FBullCowGame.h, FBullCowGame.cpp
				add These 3 Files Under Same Project
			3.Run From Main.cpp
			4.If You Use Dev Cpp or Code::Blocks Please Change Unreal Standards


6.Concept:
	In this Game Player Needs to Input a word of Given Length.
	Computer Already has a Word Inside.
	Computer checks every letter of User Input Word and Matches with Every Letter of
	the Word Inside.
	if Any of the letter of User Given Word matches with Any letter of Word Inside
		It will Check Positions
			if letter of User Given Word is in same position as The Letter of Word inside
				It will be BULLS
			if letter of User Given Word is NOT in same position as The Letter of Word inside
				It will be COWS.
	If Number Of Bulls Are Same As the Given Length in Given No. Of Tries, GAME WON
	If Number Of Bulls Are NOT Same As the Given Length in Given No. Of Tries, GAME LOOSE

		***Number Of Tries Generated Based On Length Of The Words***

7.Rules:
	Rule 1.User Needs to Input a word Of GIVEN LENGTH & GIVEN TYPE
		ex:
		Please Input 5 Letters Isogram
	--User Input: Batman	(**** Wrong *****)
	  Word Length: 6 (> 5)
	  Word Type: NOT ISOGRAM	(IsoGram = Word With No Repeated Letters: ex: Planet)

	--User Input: Eager	(**** Wrong *****)
	  Word Length: 5 (= 5)
	  Word Type: NOT ISOGRAM	(IsoGram = Word With No Repeated Letters: ex: Planet)

	--User Input: Flight	(**** Wrong *****)
	  Word Length: 6 (> 5)
	  Word Type: ISOGRAM	(IsoGram = Word With No Repeated Letters: ex: Planet)

	--User Input: Might	(**** Wrong *****)
	  Word Length: 5
	  Word Type: ISOGRAM	(IsoGram = Word With No Repeated Letters: ex: Planet)
	  	Wrong BeCause Doesn't Match with Words

	Rule 2:	For Play Again Press Y Or N
		Anything Other Than Y Or N Won't Be accepted
	Rule 3: Only 10 Turns You can Get
			If You cant find The exact word in 10 Turns, GAME OVER
	Rule 4:	User Input Must Be IN LOWEERCASE

8.Test Cases:
		Please Enter 5 Letters Isogram

	Try 1:	Batman
	Worng,Not Same Length
	
	Try 2: Eager
	Wrong,Not ISOGRAM

	Try 3: Might
	    Bulls: 4		(So, 4 Letters are Same & In Same Position as Word Inside)
	    Cows: 0
	
	Try 4: Tight
	    Bulls: 4		(So,still 4 Letters are Same & In Same Position as Word Inside)
	    Cows: 0		(So, First Letter is Different)
	
	Try 5: Light
	    Bulls: 5		(All 5 Letters are Same & In Same Position As Word Inside)
	    Cows: 0		
	             Yuppi,YOU WIN

9.Hidden Word: light

10. Inspiration : I got the Idea During My C++ Course By GameDev.tv

11.Acknowledgement: Thanks a Lot to Ben Triestem & Samuel Pattuzzi, instructors From GameDev.Tv

12.Personal Info:	
		I,Debdip Banerjee am A Computer Science Undergrad At the Time Of making this Game.
		I am Also A Game Programmer,Software Engineer,Technical Animator and Entreprenuer.
		If Anyone Wants to use Any part Of My Source Code They can.
		I am Not responsible for Any Furthur use of my Code at any Work.
		if anyone want to make any improvement they can,
		if You want to contact me,Details are Below.

13.Contact Info:
		Email: Debdipbanerjee7@gmail.com
		Whatsapp Number: 9007480046
		Contact Number: +91-9007480046
		LinkedIn Id: www.linkedin.com/in/debdip-banerjee-07
		Facebook Id: http://facebook.com/Debdipbanerjee23