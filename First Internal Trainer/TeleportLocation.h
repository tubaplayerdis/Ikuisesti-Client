#pragma once

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
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox3;
	private: System::Windows::Forms::Button^ button1;

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
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->label2->Location = System::Drawing::Point(197, 9);
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
			this->label3->Location = System::Drawing::Point(375, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Z Coordinate";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(12, 31);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(141, 20);
			this->maskedTextBox1->TabIndex = 3;
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(201, 31);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(141, 20);
			this->maskedTextBox2->TabIndex = 4;
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(379, 31);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(141, 20);
			this->maskedTextBox3->TabIndex = 5;
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
			// 
			// TeleportLocation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 120);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"TeleportLocation";
			this->Text = L"TeleportLocation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
