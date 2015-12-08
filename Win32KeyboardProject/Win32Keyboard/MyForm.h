#using <System.dll>
#using <System.Drawing.dll>
#using <System.Data.dll>
#using <System.Windows.Forms.dll>

#pragma once
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

extern std::wstring buffer;

namespace Keyboard {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::TextBox^  suggestion1;
	private: System::Windows::Forms::TextBox^  suggestion2;
	private: System::Windows::Forms::TextBox^  suggestion3;
	private: System::Windows::Forms::TextBox^  suggestion4;
	private: System::Windows::Forms::TextBox^  suggestion5;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TopLevel = TRUE;
			this->ShowInTaskbar = TRUE;
			this->AccessibleName = L"Win32Keyboard";
			this->BringToFront();
			

			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->suggestion1 = (gcnew System::Windows::Forms::TextBox());
			this->suggestion2 = (gcnew System::Windows::Forms::TextBox());
			this->suggestion3 = (gcnew System::Windows::Forms::TextBox());
			this->suggestion4 = (gcnew System::Windows::Forms::TextBox());
			this->suggestion5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(76, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Q";
			this->button1->UseVisualStyleBackColor = true;
			//this->button1->UseWaitCursor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(586, 45);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(76, 73);
			this->button2->TabIndex = 1;
			this->button2->Text = L"I";
			this->button2->UseVisualStyleBackColor = true;
			//this->button2->UseWaitCursor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(504, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(76, 73);
			this->button3->TabIndex = 2;
			this->button3->Text = L"U";
			this->button3->UseVisualStyleBackColor = true;
			//this->button3->UseWaitCursor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(422, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(76, 73);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Y";
			this->button4->UseVisualStyleBackColor = true;
			//this->button4->UseWaitCursor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(340, 45);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(76, 73);
			this->button5->TabIndex = 4;
			this->button5->Text = L"T";
			this->button5->UseVisualStyleBackColor = true;
			//this->button5->UseWaitCursor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(258, 45);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(76, 73);
			this->button6->TabIndex = 5;
			this->button6->Text = L"R";
			this->button6->UseVisualStyleBackColor = true;
			//this->button6->UseWaitCursor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(176, 45);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(76, 73);
			this->button7->TabIndex = 6;
			this->button7->Text = L"E";
			this->button7->UseVisualStyleBackColor = true;
			//this->button7->UseWaitCursor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(94, 45);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(76, 73);
			this->button8->TabIndex = 7;
			this->button8->Text = L"W";
			this->button8->UseVisualStyleBackColor = true;
			//this->button8->UseWaitCursor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(668, 45);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(76, 73);
			this->button9->TabIndex = 8;
			this->button9->Text = L"O";
			this->button9->UseVisualStyleBackColor = true;
			//this->button9->UseWaitCursor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(750, 45);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(76, 73);
			this->button10->TabIndex = 9;
			this->button10->Text = L"P";
			this->button10->UseVisualStyleBackColor = true;
			//this->button10->UseWaitCursor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(541, 124);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(76, 73);
			this->button11->TabIndex = 10;
			this->button11->Text = L"J";
			this->button11->UseVisualStyleBackColor = true;
			//this->button11->UseWaitCursor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(459, 124);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(76, 73);
			this->button12->TabIndex = 11;
			this->button12->Text = L"H";
			this->button12->UseVisualStyleBackColor = true;
			//this->button12->UseWaitCursor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(377, 124);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(76, 73);
			this->button13->TabIndex = 12;
			this->button13->Text = L"G";
			this->button13->UseVisualStyleBackColor = true;
			//this->button13->UseWaitCursor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(295, 124);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(76, 73);
			this->button14->TabIndex = 13;
			this->button14->Text = L"F";
			this->button14->UseVisualStyleBackColor = true;
			//this->button14->UseWaitCursor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(213, 124);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(76, 73);
			this->button15->TabIndex = 14;
			this->button15->Text = L"D";
			this->button15->UseVisualStyleBackColor = true;
			//this->button15->UseWaitCursor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(131, 124);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(76, 73);
			this->button16->TabIndex = 15;
			this->button16->Text = L"S";
			this->button16->UseVisualStyleBackColor = true;
			//this->button16->UseWaitCursor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(49, 124);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(76, 73);
			this->button17->TabIndex = 16;
			this->button17->Text = L"A";
			this->button17->UseVisualStyleBackColor = true;
			//this->button17->UseWaitCursor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(623, 124);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(76, 73);
			this->button18->TabIndex = 17;
			this->button18->Text = L"K";
			this->button18->UseVisualStyleBackColor = true;
			//this->button18->UseWaitCursor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(705, 124);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(76, 73);
			this->button19->TabIndex = 18;
			this->button19->Text = L"L";
			this->button19->UseVisualStyleBackColor = true;
			//this->button19->UseWaitCursor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(668, 203);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(76, 73);
			this->button20->TabIndex = 19;
			this->button20->Text = L"N";
			this->button20->UseVisualStyleBackColor = true;
			//this->button20->UseWaitCursor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(586, 203);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(76, 73);
			this->button21->TabIndex = 20;
			this->button21->Text = L"B";
			this->button21->UseVisualStyleBackColor = true;
			//this->button21->UseWaitCursor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(258, 203);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(76, 73);
			this->button22->TabIndex = 21;
			this->button22->Text = L"V";
			this->button22->UseVisualStyleBackColor = true;
			//this->button22->UseWaitCursor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(176, 203);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(76, 73);
			this->button23->TabIndex = 22;
			this->button23->Text = L"C";
			this->button23->UseVisualStyleBackColor = true;
			//this->button23->UseWaitCursor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(94, 203);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(76, 73);
			this->button24->TabIndex = 23;
			this->button24->Text = L"X";
			this->button24->UseVisualStyleBackColor = true;
			//this->button24->UseWaitCursor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(12, 203);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(76, 73);
			this->button25->TabIndex = 24;
			this->button25->Text = L"Z";
			this->button25->UseVisualStyleBackColor = true;
			//this->button25->UseWaitCursor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button26
			// 
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->Location = System::Drawing::Point(750, 203);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(76, 73);
			this->button26->TabIndex = 25;
			this->button26->Text = L"M";
			this->button26->UseVisualStyleBackColor = true;
			//this->button26->UseWaitCursor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button27
			// 
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button27->Location = System::Drawing::Point(340, 203);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(240, 73);
			this->button27->TabIndex = 26;
			this->button27->Text = L"Space";
			this->button27->UseVisualStyleBackColor = true;
			//this->button27->UseWaitCursor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button28
			// 
			this->button28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button28->Location = System::Drawing::Point(832, 45);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(115, 73);
			this->button28->TabIndex = 27;
			this->button28->Text = L"Backspace";
			this->button28->UseVisualStyleBackColor = true;
			//this->button28->UseWaitCursor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button29
			// 
			this->button29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button29->Location = System::Drawing::Point(787, 124);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(115, 73);
			this->button29->TabIndex = 28;
			this->button29->Text = L"Enter";
			this->button29->UseVisualStyleBackColor = true;
			//this->button29->UseWaitCursor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// button30
			// 
			this->button30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button30->Location = System::Drawing::Point(832, 203);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(76, 73);
			this->button30->TabIndex = 29;
			this->button30->Text = L"\x2191";
			this->button30->UseVisualStyleBackColor = true;
			//this->button30->UseWaitCursor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::keyClicked);
			// 
			// suggestion1
			// 
			this->suggestion1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestion1->Location = System::Drawing::Point(49, 13);
			this->suggestion1->Name = L"suggestion1";
			this->suggestion1->Size = System::Drawing::Size(121, 32);
			this->suggestion1->TabIndex = 30;
			this->suggestion1->Text = L"suggestion1";
			this->suggestion1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->suggestion1->UseWaitCursor = true;
			// 
			// suggestion2
			// 
			this->suggestion2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestion2->Location = System::Drawing::Point(176, 13);
			this->suggestion2->Name = L"suggestion2";
			this->suggestion2->Size = System::Drawing::Size(121, 32);
			this->suggestion2->TabIndex = 31;
			this->suggestion2->Text = L"suggestion2";
			this->suggestion2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->suggestion2->UseWaitCursor = true;
			// 
			// suggestion3
			// 
			this->suggestion3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestion3->Location = System::Drawing::Point(303, 13);
			this->suggestion3->Name = L"suggestion3";
			this->suggestion3->Size = System::Drawing::Size(121, 32);
			this->suggestion3->TabIndex = 32;
			this->suggestion3->Text = L"suggestion3";
			this->suggestion3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->suggestion3->UseWaitCursor = true;
			// 
			// suggestion4
			// 
			this->suggestion4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestion4->Location = System::Drawing::Point(430, 13);
			this->suggestion4->Name = L"suggestion4";
			this->suggestion4->Size = System::Drawing::Size(121, 32);
			this->suggestion4->TabIndex = 33;
			this->suggestion4->Text = L"suggestion4";
			this->suggestion4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->suggestion4->UseWaitCursor = true;
			// 
			// suggestion5
			// 
			this->suggestion5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestion5->Location = System::Drawing::Point(557, 13);
			this->suggestion5->Name = L"suggestion5";
			this->suggestion5->Size = System::Drawing::Size(121, 32);
			this->suggestion5->TabIndex = 34;
			this->suggestion5->Text = L"suggestion5";
			this->suggestion5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->suggestion5->UseWaitCursor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(951, 294);
			this->Controls->Add(this->suggestion5);
			this->Controls->Add(this->suggestion4);
			this->Controls->Add(this->suggestion3);
			this->Controls->Add(this->suggestion2);
			this->Controls->Add(this->suggestion1);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Name = L"MyForm";
			this->Text = L" ";
			this->UseWaitCursor = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	protected:
		virtual property System::Windows::Forms::CreateParams ^CreateParams
		{
			System::Windows::Forms::CreateParams ^get() override
			{
				System::Windows::Forms::CreateParams ^cp = __super::CreateParams;
				cp->ExStyle |= WS_EX_NOACTIVATE;
				return cp;
			}
		}

	
	private: System::Void keyClicked(System::Object^  sender, System::EventArgs^  e) {
		//MessageBox.Show(L"You Clicked My Button!");
		System::Windows::Forms::Button^ thisButton = ((System::Windows::Forms::Button^)sender);
		HWND activeWindow = GetActiveWindow();
		System::String ^textToEnter = thisButton->Text;

		std::string localStr = "Local";
		if (thisButton->Text == L"Space") {
			std::cout << L"\ncout: SPACE" << std::endl;
			std::cerr << L"cerr: SPACE" << std::endl;
			std::wcerr << L"wcerr: SPACE" << std::endl;
			textToEnter = " ";
		}
		else if (thisButton->Text == L"Enter") {
			std::cout << L"\ncout: ENTER" << std::endl;
			std::cerr << L"cerr: ENTER" << std::endl;
			std::wcerr << L"wcerr: ENTER" << std::endl;
			textToEnter = "{ENTER}";
		}
		else if (thisButton->Text == L"Backspace") {
			std::cout << L"\ncout: ENTER" << std::endl;
			std::cerr << L"cerr: ENTER" << std::endl;
			std::wcerr << L"wcerr: ENTER" << std::endl;
			textToEnter = "{BACKSPACE}";
		}

		SendKeys::Send(textToEnter);
	}
	};
}
