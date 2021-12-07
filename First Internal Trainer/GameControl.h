#pragma once
#include "LogFrameWork.h"
#include "Armor.h"

namespace FirstInternalTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameControl
	/// </summary>
	public ref class GameControl : public System::Windows::Forms::Form
	{
	public:
		GameControl(void)
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
		~GameControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ CurrentGameSpeedNumeric;

	private: System::Windows::Forms::Timer^ GetGameSpeedTimer;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CurrentGameSpeedNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->GetGameSpeedTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentGameSpeedNumeric))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(8, 75);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(232, 20);
			this->numericUpDown1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 6);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Armor Value";
			// 
			// CurrentGameSpeedNumeric
			// 
			this->CurrentGameSpeedNumeric->Location = System::Drawing::Point(8, 21);
			this->CurrentGameSpeedNumeric->Margin = System::Windows::Forms::Padding(2);
			this->CurrentGameSpeedNumeric->Name = L"CurrentGameSpeedNumeric";
			this->CurrentGameSpeedNumeric->ReadOnly = true;
			this->CurrentGameSpeedNumeric->Size = System::Drawing::Size(232, 20);
			this->CurrentGameSpeedNumeric->TabIndex = 2;
			// 
			// GetGameSpeedTimer
			// 
			this->GetGameSpeedTimer->Enabled = true;
			this->GetGameSpeedTimer->Interval = 1000;
			this->GetGameSpeedTimer->Tick += gcnew System::EventHandler(this, &GameControl::GetGameSpeedTimer_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 60);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Set Armor";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 96);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(232, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// GameControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 343);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->CurrentGameSpeedNumeric);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"GameControl";
			this->Text = L"GameControl";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentGameSpeedNumeric))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GetGameSpeedTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			CurrentGameSpeedNumeric->Value = Convert::ToDecimal(GetCorsshairSize());
		}
		catch (std::exception p)
		{
			AddToOutputCashe(p.what());
		}
		
	}
};
}
