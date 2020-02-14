#pragma once
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "mem.h"
#include "proc.h"
#include "library.h"
#include "MyForm.h"
#include <string.h>
#include "Stdafx.h"
#include "pch.h"

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
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::CheckBox^ checkBox9;
	private: System::Windows::Forms::CheckBox^ checkBox10;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
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
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 20);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 15);
			this->label1->TabIndex = 26;
			this->label1->Text = L"X = ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 48);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 15);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Y = ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 75);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 15);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Z = ";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 18);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 29;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(57, 45);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 30;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(57, 73);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 31;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(5, 23);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(100, 19);
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
			this->checkBox2->Size = System::Drawing::Size(96, 19);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"Mana Cheat";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged_1);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(5, 71);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(120, 19);
			this->checkBox3->TabIndex = 34;
			this->checkBox3->Text = L"Keep Item Cheat";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(5, 95);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(188, 19);
			this->checkBox4->TabIndex = 35;
			this->checkBox4->Text = L"Increase Gun Damage Cheat";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(5, 119);
			this->checkBox5->Margin = System::Windows::Forms::Padding(2);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(193, 19);
			this->checkBox5->TabIndex = 36;
			this->checkBox5->Text = L"Increase Spell Damage Cheat";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(5, 143);
			this->checkBox6->Margin = System::Windows::Forms::Padding(2);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(205, 19);
			this->checkBox6->TabIndex = 37;
			this->checkBox6->Text = L"Unlimited Weapon Ammo Cheat";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(5, 167);
			this->checkBox7->Margin = System::Windows::Forms::Padding(2);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(180, 19);
			this->checkBox7->TabIndex = 38;
			this->checkBox7->Text = L"Increase Walk Speed Cheat";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(5, 191);
			this->checkBox8->Margin = System::Windows::Forms::Padding(2);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(184, 19);
			this->checkBox8->TabIndex = 39;
			this->checkBox8->Text = L"Increase Jump Speed Cheat";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox8_CheckedChanged);
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(5, 215);
			this->checkBox9->Margin = System::Windows::Forms::Padding(2);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(244, 19);
			this->checkBox9->TabIndex = 40;
			this->checkBox9->Text = L"Increase Jump Speed Hold Time Cheat";
			this->checkBox9->UseVisualStyleBackColor = true;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox9_CheckedChanged_1);
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(5, 239);
			this->checkBox10->Margin = System::Windows::Forms::Padding(2);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(74, 19);
			this->checkBox10->TabIndex = 41;
			this->checkBox10->Text = L"Teleport";
			this->checkBox10->UseVisualStyleBackColor = true;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox10_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->checkBox10);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox9);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox8);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox7);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->checkBox6);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Location = System::Drawing::Point(12, 90);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(304, 353);
			this->groupBox1->TabIndex = 42;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox2->Location = System::Drawing::Point(84, 239);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 100);
			this->groupBox2->TabIndex = 43;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(365, 450);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"PwnTrainer By RuNt1M3 T3RroR";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox7->Checked) {
			cheat::modWalkSpeed(localPlayerPtr1, 1);
		}
		else {
			cheat::modWalkSpeed(localPlayerPtr1, 0);
		}
	}
	private: System::Void checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox8->Checked) {
			cheat::increaseJumpSpeed(localPlayerPtr1, 1);
		}
		else {
			cheat::increaseJumpSpeed(localPlayerPtr1, 0);
		}
	}
	private: System::Void checkBox9_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox9->Checked) {
			cheat::increaseJumpHoldTime(localPlayerPtr1, 1);
		}
		else {
			cheat::increaseJumpHoldTime(localPlayerPtr1, 0);
		}

	}
	private: System::Void checkBox10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GameLogic.dll");
		uintptr_t localPlayerPtr = (uintptr_t)(moduleBase + 0x97E1C);
		uintptr_t localPlayerPtr1 = (uintptr_t)(moduleBase + 0x97D7C);
		if (checkBox10->Checked) {
			//call teleport here
		}
		else {
			//close teleport call here
		}
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
};
}
