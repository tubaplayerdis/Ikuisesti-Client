#pragma once
#include "CoordChange.h"

namespace FirstInternalTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TeleportLocation
	/// </summary>
	public ref class TeleportLocation : public System::Windows::Forms::Form
	{
	public:
		TeleportLocation(void)
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
		~TeleportLocation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownX;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownY;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownZ;
	private: System::Windows::Forms::Timer^ GetNewCorrds;
	private: System::Windows::Forms::TextBox^ textBoxZ;
	private: System::Windows::Forms::TextBox^ textBoxY;
	private: System::Windows::Forms::TextBox^ textBoxX;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownZ = (gcnew System::Windows::Forms::NumericUpDown());
			this->GetNewCorrds = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBoxZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X Coordinate";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(186, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Y Coordinate";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(363, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Z Coordinate";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 57);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(508, 46);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Teleport!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TeleportLocation::button1_Click);
			// 
			// numericUpDownX
			// 
			this->numericUpDownX->DecimalPlaces = 5;
			this->numericUpDownX->Location = System::Drawing::Point(12, 31);
			this->numericUpDownX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDownX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, System::Int32::MinValue });
			this->numericUpDownX->Name = L"numericUpDownX";
			this->numericUpDownX->Size = System::Drawing::Size(153, 20);
			this->numericUpDownX->TabIndex = 7;
			// 
			// numericUpDownY
			// 
			this->numericUpDownY->DecimalPlaces = 5;
			this->numericUpDownY->Location = System::Drawing::Point(190, 31);
			this->numericUpDownY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDownY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, System::Int32::MinValue });
			this->numericUpDownY->Name = L"numericUpDownY";
			this->numericUpDownY->Size = System::Drawing::Size(153, 20);
			this->numericUpDownY->TabIndex = 8;
			// 
			// numericUpDownZ
			// 
			this->numericUpDownZ->DecimalPlaces = 5;
			this->numericUpDownZ->Location = System::Drawing::Point(367, 31);
			this->numericUpDownZ->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDownZ->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, System::Int32::MinValue });
			this->numericUpDownZ->Name = L"numericUpDownZ";
			this->numericUpDownZ->Size = System::Drawing::Size(153, 20);
			this->numericUpDownZ->TabIndex = 9;
			// 
			// GetNewCorrds
			// 
			this->GetNewCorrds->Enabled = true;
			this->GetNewCorrds->Interval = 10;
			this->GetNewCorrds->Tick += gcnew System::EventHandler(this, &TeleportLocation::GetNewCorrds_Tick);
			// 
			// textBoxZ
			// 
			this->textBoxZ->Location = System::Drawing::Point(564, 83);
			this->textBoxZ->Name = L"textBoxZ";
			this->textBoxZ->ReadOnly = true;
			this->textBoxZ->Size = System::Drawing::Size(129, 20);
			this->textBoxZ->TabIndex = 10;
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(564, 57);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->ReadOnly = true;
			this->textBoxY->Size = System::Drawing::Size(129, 20);
			this->textBoxY->TabIndex = 11;
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(564, 31);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->ReadOnly = true;
			this->textBoxX->Size = System::Drawing::Size(129, 20);
			this->textBoxX->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(560, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 19);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Current Coords";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(540, 31);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 19);
			this->label5->TabIndex = 14;
			this->label5->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(540, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 19);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(540, 83);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 19);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Z";
			// 
			// TeleportLocation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 113);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxX);
			this->Controls->Add(this->textBoxY);
			this->Controls->Add(this->textBoxZ);
			this->Controls->Add(this->numericUpDownZ);
			this->Controls->Add(this->numericUpDownY);
			this->Controls->Add(this->numericUpDownX);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"TeleportLocation";
			this->Text = L"TeleportLocation";
			this->Load += gcnew System::EventHandler(this, &TeleportLocation::TeleportLocation_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		GetNewCorrds->Enabled = false;
		Sleep(10);

		double Xc = Decimal::ToDouble(numericUpDownX->Value);
		double Yc = Decimal::ToDouble(numericUpDownY->Value);
		double Zc = Decimal::ToDouble(numericUpDownZ->Value);
		
		Coordinates Coords;
		Coords.X = Xc;
		Coords.Y = Yc;
		Coords.Z = Zc;

		SetCoordinates(Coords);
		this->Close();


		

	}
private: System::Void TeleportLocation_Load(System::Object^ sender, System::EventArgs^ e) {
		

		Decimal X = System::Convert::ToDecimal(ReturnXvalue());
		Decimal Y = System::Convert::ToDecimal(ReturnYvalue());
		Decimal Z = System::Convert::ToDecimal(ReturnZvalue());
		numericUpDownX->Value = X;
		numericUpDownY->Value = Y;
		numericUpDownZ->Value = Z;

}
private: System::Void GetNewCorrds_Tick(System::Object^ sender, System::EventArgs^ e) {
	textBoxX->Text = ReturnXvalue().ToString();
	textBoxY->Text = ReturnYvalue().ToString();
	textBoxZ->Text = ReturnZvalue().ToString();
}

};
}
