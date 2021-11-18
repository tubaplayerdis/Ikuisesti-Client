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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownZ = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->label1->Location = System::Drawing::Point(12, 9);
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
			this->button1->Size = System::Drawing::Size(508, 53);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Teleport!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TeleportLocation::button1_Click);
			// 
			// numericUpDownX
			// 
			this->numericUpDownX->DecimalPlaces = 5;
			this->numericUpDownX->Location = System::Drawing::Point(12, 31);
			this->numericUpDownX->Name = L"numericUpDownX";
			this->numericUpDownX->Size = System::Drawing::Size(153, 20);
			this->numericUpDownX->TabIndex = 7;
			// 
			// numericUpDownY
			// 
			this->numericUpDownY->DecimalPlaces = 5;
			this->numericUpDownY->Location = System::Drawing::Point(190, 31);
			this->numericUpDownY->Name = L"numericUpDownY";
			this->numericUpDownY->Size = System::Drawing::Size(153, 20);
			this->numericUpDownY->TabIndex = 8;
			// 
			// numericUpDownZ
			// 
			this->numericUpDownZ->DecimalPlaces = 5;
			this->numericUpDownZ->Location = System::Drawing::Point(367, 31);
			this->numericUpDownZ->Name = L"numericUpDownZ";
			this->numericUpDownZ->Size = System::Drawing::Size(153, 20);
			this->numericUpDownZ->TabIndex = 9;
			// 
			// TeleportLocation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 120);
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

		double Xc = Decimal::ToDouble(numericUpDownX->Value);
		double Yc = Decimal::ToDouble(numericUpDownY->Value);
		double Zc = Decimal::ToDouble(numericUpDownZ->Value);
		


		SetCoordinates(Xc, Yc, Zc);

	}
private: System::Void TeleportLocation_Load(System::Object^ sender, System::EventArgs^ e) {
		
	numericUpDownX->Value = ReturnXvalue();


}
};
}
