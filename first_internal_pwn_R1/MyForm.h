#pragma once
#include <windows.h>
#include <iostream>
#include "mem.h"
#include "library.h"
#include "MyForm.h"
#include <string.h>


namespace GuiDLL {

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

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ Damage;
	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;

	

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton4;

	private: System::Windows::Forms::Button^ button1;

	private: System::ComponentModel::IContainer^ components;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->Damage = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->Damage->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"X = ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 49);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Y = ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 76);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Z = ";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(45, 19);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 29;
			this->textBox1->Text = L"-43651";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(45, 46);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 30;
			this->textBox2->Text = L"-55970";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(45, 74);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 31;
			this->textBox3->Text = L"324";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(5, 23);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(88, 17);
			this->checkBox1->TabIndex = 32;
			this->checkBox1->Text = L"Health Cheat";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(5, 47);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(84, 17);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"Mana Cheat";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged_1);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(7, 18);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(105, 17);
			this->checkBox3->TabIndex = 34;
			this->checkBox3->Text = L"Keep Item Cheat";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(5, 18);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(164, 17);
			this->checkBox4->TabIndex = 35;
			this->checkBox4->Text = L"Increase Gun Damage Cheat";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(5, 41);
			this->checkBox5->Margin = System::Windows::Forms::Padding(2);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(167, 17);
			this->checkBox5->TabIndex = 36;
			this->checkBox5->Text = L"Increase Spell Damage Cheat";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(5, 64);
			this->checkBox6->Margin = System::Windows::Forms::Padding(2);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(176, 17);
			this->checkBox6->TabIndex = 37;
			this->checkBox6->Text = L"Unlimited Weapon Ammo Cheat";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Location = System::Drawing::Point(12, 110);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(188, 81);
			this->groupBox1->TabIndex = 42;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Health/Mana Mod";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox2->Location = System::Drawing::Point(12, 356);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(188, 102);
			this->groupBox2->TabIndex = 43;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Walk/Run Mod";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(9, 69);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(100, 17);
			this->radioButton3->TabIndex = 41;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"4X Walk Speed";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(9, 44);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(94, 17);
			this->radioButton2->TabIndex = 40;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"2X Walk Seed";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(9, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(120, 17);
			this->radioButton1->TabIndex = 39;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Normal Walk Speed";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// Damage
			// 
			this->Damage->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Damage->Controls->Add(this->checkBox4);
			this->Damage->Controls->Add(this->checkBox5);
			this->Damage->Controls->Add(this->checkBox6);
			this->Damage->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Damage->Location = System::Drawing::Point(210, 110);
			this->Damage->Name = L"Damage";
			this->Damage->Size = System::Drawing::Size(217, 100);
			this->Damage->TabIndex = 43;
			this->Damage->TabStop = false;
			this->Damage->Text = L"Damage Mod";
			this->Damage->Enter += gcnew System::EventHandler(this, &MyForm::groupBox3_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox3->Location = System::Drawing::Point(210, 210);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(217, 106);
			this->groupBox3->TabIndex = 44;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Teleportation Mod";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &MyForm::groupBox3_Enter_1);
			// 
			// button1
			// 
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGreen;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LimeGreen;
			this->button1->Location = System::Drawing::Point(132, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"Submit";
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox5->Controls->Add(this->checkBox3);
			this->groupBox5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox5->Location = System::Drawing::Point(210, 315);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(217, 51);
			this->groupBox5->TabIndex = 46;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Inventory Mod";
			this->groupBox5->Enter += gcnew System::EventHandler(this, &MyForm::groupBox5_Enter);
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox6->Controls->Add(this->checkBox7);
			this->groupBox6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox6->Location = System::Drawing::Point(12, 193);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(188, 51);
			this->groupBox6->TabIndex = 47;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Jump Hold Time Mod";
			this->groupBox6->Enter += gcnew System::EventHandler(this, &MyForm::groupBox6_Enter);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(9, 18);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(137, 17);
			this->checkBox7->TabIndex = 42;
			this->checkBox7->TabStop = true;
			this->checkBox7->Text = L"Infinite Jump Hold Time";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->radioButton6);
			this->groupBox4->Controls->Add(this->radioButton5);
			this->groupBox4->Controls->Add(this->radioButton4);
			this->groupBox4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox4->Location = System::Drawing::Point(12, 250);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(188, 100);
			this->groupBox4->TabIndex = 48;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Jump Speed Mod";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(10, 70);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(100, 17);
			this->radioButton6->TabIndex = 2;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"4X Jump Speed";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton6_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(10, 45);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(100, 17);
			this->radioButton5->TabIndex = 1;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"2X Jump Speed";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(10, 20);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(120, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Normal Jump Speed";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(444, 503);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->Damage);
			this->Controls->Add(this->groupBox1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Name = L"MyForm";
			this->Text = L"PwnTrainer By RuNt1M3 T3RroR";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->Damage->ResumeLayout(false);
			this->Damage->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox1->Checked) {
			cheat::modPlayerHealth(localPlayerPtr, 1);
		}
		else {
			cheat::modPlayerHealth(localPlayerPtr, 0);
		}
	}
	private: System::Void checkBox2_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox2->Checked) {
			cheat::modPlayerMana(localPlayerPtr, moduleBase, 1);
		}
		else {
			cheat::modPlayerMana(localPlayerPtr, moduleBase, 0);
		}
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox3->Checked) {
			cheat::KeepItems(moduleBase, 1);
		}
		else {
			cheat::KeepItems(moduleBase, 0);
		}
	}
	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox4->Checked) {
			cheat::IncreasedGunDamage(moduleBase, 1);
		}
		else {
			cheat::IncreasedGunDamage(moduleBase, 0);
		}
	}
	private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox5->Checked) {
			cheat::IncreasedSpellDamage(moduleBase, 1);
		}
		else {
			cheat::IncreasedSpellDamage(moduleBase, 0);
		}
	}
	private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox6->Checked) {
			cheat::UnlimitedAmmo(moduleBase, 1);
		}
		else {
			cheat::UnlimitedAmmo(moduleBase, 0);
		}
	}
	private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox7->Checked) {
			cheat::increaseJumpHoldTime(localPlayerPtr1, 1);
		}
		else {
			cheat::increaseJumpHoldTime(localPlayerPtr1, 0);
		}
	}

	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		cheat::modWalkSpeed(localPlayerPtr1, 1);
	}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	cheat::modWalkSpeed(localPlayerPtr1, 2);
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	cheat::modWalkSpeed(localPlayerPtr1, 4);
}
private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	cheat::increaseJumpSpeed(localPlayerPtr1, 1);

}
private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	cheat::increaseJumpSpeed(localPlayerPtr1, 2);
}
private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	cheat::increaseJumpSpeed(localPlayerPtr1, 4);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
	uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
	uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
	float xPos, yPos, zPos;
	xPos = float::Parse(textBox1->Text);
	yPos = float::Parse(textBox2->Text);
	zPos = float::Parse(textBox3->Text);
	cheat::Teleport(localPlayerPtr, xPos, yPos, zPos);
}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox3_Enter_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox5_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox6_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}

};
}
