#pragma once

#include "thread"
#include "functions.h"

namespace GaussianBlur {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ CPPRadioBox;
	private: System::Windows::Forms::RadioButton^ ASMRadioBox;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Button^ loadButton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->CPPRadioBox = (gcnew System::Windows::Forms::RadioButton());
			   this->ASMRadioBox = (gcnew System::Windows::Forms::RadioButton());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->startButton = (gcnew System::Windows::Forms::Button());
			   this->loadButton = (gcnew System::Windows::Forms::Button());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // CPPRadioBox
			   // 
			   this->CPPRadioBox->AutoSize = true;
			   this->CPPRadioBox->Checked = true;
			   this->CPPRadioBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->CPPRadioBox->Location = System::Drawing::Point(541, 21);
			   this->CPPRadioBox->Name = L"CPPRadioBox";
			   this->CPPRadioBox->Size = System::Drawing::Size(49, 20);
			   this->CPPRadioBox->TabIndex = 0;
			   this->CPPRadioBox->TabStop = true;
			   this->CPPRadioBox->Text = L"C++";
			   this->CPPRadioBox->UseVisualStyleBackColor = true;
			   // 
			   // ASMRadioBox
			   // 
			   this->ASMRadioBox->AutoSize = true;
			   this->ASMRadioBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			   this->ASMRadioBox->Location = System::Drawing::Point(596, 21);
			   this->ASMRadioBox->Name = L"ASMRadioBox";
			   this->ASMRadioBox->Size = System::Drawing::Size(55, 21);
			   this->ASMRadioBox->TabIndex = 1;
			   this->ASMRadioBox->Text = L"ASM";
			   this->ASMRadioBox->UseVisualStyleBackColor = true;
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(64) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					   L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					   L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
					   L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60", L"61", L"62",
					   L"63", L"64"
			   });
			   this->comboBox1->Location = System::Drawing::Point(734, 20);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(55, 24);
			   this->comboBox1->TabIndex = 3;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			   this->label1->Location = System::Drawing::Point(681, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(47, 17);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Wątki:";
			   // 
			   // startButton
			   // 
			   this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->startButton->Location = System::Drawing::Point(348, 16);
			   this->startButton->Name = L"startButton";
			   this->startButton->Size = System::Drawing::Size(161, 30);
			   this->startButton->TabIndex = 5;
			   this->startButton->Text = L"Rozmyj obraz używając:";
			   this->startButton->UseVisualStyleBackColor = true;
			   this->startButton->Click += gcnew System::EventHandler(this, &MyForm::startButtonHandler);
			   // 
			   // loadButton
			   // 
			   this->loadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->loadButton->Location = System::Drawing::Point(160, 16);
			   this->loadButton->Margin = System::Windows::Forms::Padding(2);
			   this->loadButton->Name = L"loadButton";
			   this->loadButton->Size = System::Drawing::Size(161, 30);
			   this->loadButton->TabIndex = 21;
			   this->loadButton->Text = L"Załaduj obraz";
			   this->loadButton->UseVisualStyleBackColor = true;
			   this->loadButton->Click += gcnew System::EventHandler(this, &MyForm::loadButtonHandler);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->label3->Location = System::Drawing::Point(27, 20);
			   this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(0, 17);
			   this->label3->TabIndex = 22;
			   this->label3->Visible = false;
			   // 
			   // label5
			   // 
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(953, 23);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(179, 19);
			   this->label5->TabIndex = 0;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->pictureBox2->Location = System::Drawing::Point(596, 65);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(550, 450);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 26;
			   this->pictureBox2->TabStop = false;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->pictureBox1->Location = System::Drawing::Point(14, 65);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(550, 450);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 25;
			   this->pictureBox1->TabStop = false;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(839, 23);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(108, 16);
			   this->label2->TabIndex = 27;
			   this->label2->Text = L"Czas wykonania:";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1163, 525);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->loadButton);
			   this->Controls->Add(this->startButton);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->ASMRadioBox);
			   this->Controls->Add(this->CPPRadioBox);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();
			   this->comboBox1->Text = std::thread::hardware_concurrency().ToString();
		   }
#pragma endregion

	private: System::Void startButtonHandler(System::Object^ sender, System::EventArgs^ e) {
		String^ fileName = this->label3->Text;
		String^ threadsCount = this->comboBox1->Text;
		bool isCPPChecked;
		if (this->CPPRadioBox->Checked == true)
			isCPPChecked = true;
		else
			isCPPChecked = false;
		if (validateInput(fileName)) {
			int time = blur(fileName, threadsCount, isCPPChecked);
			this->pictureBox2->ImageLocation = L".\\after.bmp";
			int milliseconds = time / 1000;
			int microseconds = time % 1000;
			String^ millisecondsText = milliseconds + "." + microseconds + " ms";
			this->label5->Text = millisecondsText;
		}
	}

	private: System::Void loadButtonHandler(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::OpenFileDialog^ openDialog = gcnew OpenFileDialog;
		openDialog->Filter = "Bitmap(*.bmp)|*.bmp";
		openDialog->RestoreDirectory = true;
		openDialog->ShowHelp = true;
		if (openDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openDialog->FileName != nullptr) {
				this->label3->Text = openDialog->FileName;
				this->pictureBox1->ImageLocation = openDialog->FileName;
			}
		}
	}
	};
}
