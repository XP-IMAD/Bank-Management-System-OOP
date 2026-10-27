#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:

	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string Text)
	{
		return Text.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static void PrintFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		cout << "\nPrint First Letter From Each Word :\n";

		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				cout << Text[i] << endl;
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Text)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;

	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;

	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string UpperAllString(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}

		return Text;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}

		return Text;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}

	static string InvertAllLettersCase(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
			{
				Text[i] = InvertLetterCase(Text[i]);
			}
		}

		return Text;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}


	static short CountSmallLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}


	static short CountSpecificLetter(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (MatchCase)
			{
				if (Text[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(Text[i]) == tolower(Letter))
					Counter++;

			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
	}

	static short CountVowels(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{

			if (IsVowel(Text[i]))
				Counter++;

		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowelsInString(string Text)
	{
		cout << "\nVowel in String are :  ";

		for (short i = 0; i < Text.length(); i++)
		{

			if (IsVowel(Text[i]))
				cout << Text[i] << "  ";

		}

		cout << "\n";

	}

	void PrintVowelsInString()
	{
		PrintVowelsInString(_Value);
	}

	static void PrintEachWordInString(string Text)
	{
		string delim = " ";

		cout << "Your String Words Are :\n\n";
		short pos = 0;
		string sWord;

		while ((pos = Text.find(delim)) != Text.npos)
		{
			sWord = Text.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			Text.erase(0, (pos + delim.length()));
		}

		if (Text != "")
		{
			cout << Text << endl;
		}
	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static short CountWords(string Text)
	{
		short Counter = 0;
		string delim = " ";

		short pos = 0;
		string sWord;

		while ((pos = Text.find(delim)) != Text.npos)
		{
			sWord = Text.substr(0, pos);

			if (sWord != "")
			{
				Counter++;
			}

			Text.erase(0, (pos + delim.length()));
		}

		if (Text != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static vector<string> Split(string Text, string delim)
	{
		vector<string> vWords;

		short position = 0;
		string sWord;

		while ((position = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, position);
			if (sWord != "")
			{
				vWords.push_back(sWord);
			}

			Text.erase(0, position + delim.length());

		}
		if (Text != "")
		{
			vWords.push_back(Text);
		}

		return vWords;
	}

	vector<string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string TrimLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
				return Text.substr(i, Text.length() - i);
		}
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
				return Text.substr(0, i + 1);
		}
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		return TrimLeft(TrimRight(Text));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>& vString, string delim)
	{
		string Word;

		for (string& S1 : vString)
		{
			Word += S1 + delim;
		}

		return Word.substr(0, Word.length() - delim.length());
	}

	static string JoinString(string arr[], short arrLength, string delim)
	{
		string Word;

		for (short i = 0; i < arrLength; i++)
		{
			Word += arr[i] + delim;
		}

		return Word.substr(0, Word.length() - delim.length());
	}

	static string ReversedString(string Text)
	{
		string Word;

		vector <string> vString;
		vString = Split(Text, " ");

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;
			Word += *iter + " ";
		}

		return Word.substr(0, Word.length() - 1);
	}

	void ReversedString()
	{
		_Value = ReversedString(_Value);
	}

	static string ReplaceWordInString(string Text, string StringToReplace, string ReplaceTo, bool MatchCase = true)
	{
		vector <string> vString = Split(Text, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
					s = ReplaceTo;
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
					s = ReplaceTo;
			}
		}

		return JoinString(vString, " ");
	}

	void ReplaceWordInString(string WordToReplace, string ReplaceTo, bool MatchCase)
	{
		_Value = ReplaceWordInString(_Value, WordToReplace, ReplaceTo, MatchCase);
	}

	static string RemovePunctuations(string Text)
	{
		string S1;

		for (short i = 0; i < Text.length(); i++)
		{
			if (!ispunct(Text[i]))
			{
				S1 += Text[i];
			}

		}

		return S1;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}


};

