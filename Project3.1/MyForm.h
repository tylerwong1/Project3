#pragma once
#include "sorting.cpp"
#include <string>
#include <map>
#include <iomanip>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

namespace Project31 {

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ cb_category;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tb_numOut;

	private: System::Windows::Forms::ComboBox^ cb_sort;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ rtb_output;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tb_time;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->cb_category = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_numOut = (gcnew System::Windows::Forms::TextBox());
			this->cb_sort = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rtb_output = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tb_time = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(266, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(238, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Covid-19 Data";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(37, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Category";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(42, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 42);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Generate\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// cb_category
			// 
			this->cb_category->AllowDrop = true;
			this->cb_category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_category->FormattingEnabled = true;
			this->cb_category->Location = System::Drawing::Point(42, 87);
			this->cb_category->MaxDropDownItems = 3;
			this->cb_category->Name = L"cb_category";
			this->cb_category->Size = System::Drawing::Size(168, 28);
			this->cb_category->TabIndex = 4;
			this->cb_category->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(37, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(192, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Number of Outputs";
			// 
			// tb_numOut
			// 
			this->tb_numOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_numOut->Location = System::Drawing::Point(42, 255);
			this->tb_numOut->Name = L"tb_numOut";
			this->tb_numOut->Size = System::Drawing::Size(168, 26);
			this->tb_numOut->TabIndex = 8;
			// 
			// cb_sort
			// 
			this->cb_sort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_sort->FormattingEnabled = true;
			this->cb_sort->Location = System::Drawing::Point(42, 168);
			this->cb_sort->Name = L"cb_sort";
			this->cb_sort->Size = System::Drawing::Size(168, 28);
			this->cb_sort->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(37, 140);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(158, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Sorting Method";
			// 
			// rtb_output
			// 
			this->rtb_output->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtb_output->Location = System::Drawing::Point(317, 84);
			this->rtb_output->Name = L"rtb_output";
			this->rtb_output->Size = System::Drawing::Size(381, 308);
			this->rtb_output->TabIndex = 12;
			this->rtb_output->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(313, 443);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 24);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Time: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(383, 428);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 14;
			// 
			// tb_time
			// 
			this->tb_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_time->Location = System::Drawing::Point(382, 440);
			this->tb_time->Name = L"tb_time";
			this->tb_time->Size = System::Drawing::Size(316, 29);
			this->tb_time->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 502);
			this->Controls->Add(this->tb_time);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->rtb_output);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cb_sort);
			this->Controls->Add(this->tb_numOut);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cb_category);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Covid Data Tracker";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		//add items to category combo box
		cb_category->Items->Add("New Cases");
		cb_category->Items->Add("New Deaths");
		cb_category->Items->Add("New Vaccinations");

		// add items to sort combo box
		cb_sort->Items->Add("Merge");
		cb_sort->Items->Add("Quick");
		cb_sort->Items->Add("Heap");
		cb_sort->Items->Add("Optimized Bubble");

		
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
		 // click generate button
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// clear textbox
	rtb_output->Clear();
	tb_time->Clear();

	// converting drop down menu into usable strings
	String^ cat = System::Convert::ToString(cb_category->Text);
	String^ numOut = System::Convert::ToString(tb_numOut->Text);
	String^ sort = System::Convert::ToString(cb_sort->Text);

	// convert System string to std::string
	msclr::interop::marshal_context context;
	std::string catConvert = context.marshal_as<std::string>(cat);
	std::string numConvert = context.marshal_as<std::string>(numOut);
	std::string sortConvert = context.marshal_as<std::string>(sort);

	// changing string to match the keys of the map for Entry object
	if (catConvert == "New Cases")
		catConvert = "cases";
	else if (catConvert == "New Deaths")
		catConvert = "deaths";
	else if (catConvert == "New Vaccinations")
		catConvert = "vax";

	//retrieve data from csv file
	std::vector<Entry> data = getData();
	// sort according to user input
	if (sortConvert == "Quick") {
		// time the function
		auto begin = std::chrono::high_resolution_clock::now();
		// perform sort
		quickSort(data, 0, data.size() - 1, catConvert);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

		// print to window
		for (int i = data.size() - 1; i >= data.size() - stoi(numConvert); i--) {
			rtb_output->Text += context.marshal_as<String^>(data[i].country) + "   ";
			rtb_output->Text += context.marshal_as<String^>(data[i].date) + "   ";
			rtb_output->Text += System::Convert::ToString(data[i].data[catConvert]);
			rtb_output->Text += "\r\n";

		}
		// print timing of sort
		tb_time->Text = System::Convert::ToString(elapsed.count() * 1e-9) + " seconds!";
	}
	else if (sortConvert == "Heap") {
		// time the function
		auto begin = std::chrono::high_resolution_clock::now();
		// perform sort
		heapSort(data, catConvert);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

		// print to window
		for (int i = data.size() - 1; i >= data.size() - stoi(numConvert); i--) {
			rtb_output->Text += context.marshal_as<String^>(data[i].country) + "   ";
			rtb_output->Text += context.marshal_as<String^>(data[i].date) + "   ";
			rtb_output->Text += System::Convert::ToString(data[i].data[catConvert]);
			rtb_output->Text += "\r\n";
		}
		// print timing of sort
		tb_time->Text = System::Convert::ToString(elapsed.count() * 1e-9) + " seconds!";
	}
	else if (sortConvert == "Merge") {
		// time the function
		auto begin = std::chrono::high_resolution_clock::now();
		std::vector<Entry> temp(data.size());
		// perform sort
		mergeSort(data, temp, 0, data.size() - 1, catConvert);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

		// print to window
		for (int i = data.size() - 1; i >= data.size() - stoi(numConvert); i--) {
			rtb_output->Text += context.marshal_as<String^>(data[i].country) + "   ";
			rtb_output->Text += context.marshal_as<String^>(data[i].date) + "   ";
			rtb_output->Text += System::Convert::ToString(data[i].data[catConvert]);
			rtb_output->Text += "\r\n";

		}
		// print timing of sort
		tb_time->Text = System::Convert::ToString(elapsed.count() * 1e-9) + " seconds!";
	}
	else if (sortConvert == "Optimized Bubble") {
		// time the function
		auto begin = std::chrono::high_resolution_clock::now();
		// perform sort
		optimizedBubbleSort(data, catConvert, stoi(numConvert));
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

		// print to window
		for (int i = data.size() - 1; i >= data.size() - stoi(numConvert); i--) {
			rtb_output->Text += context.marshal_as<String^>(data[i].country) + "   ";
			rtb_output->Text += context.marshal_as<String^>(data[i].date) + "   ";
			rtb_output->Text += System::Convert::ToString(data[i].data[catConvert]);
			rtb_output->Text += "\r\n";

		}
		// print timing of sort
		tb_time->Text = System::Convert::ToString(elapsed.count() * 1e-9) + " seconds!";
	}
}
};
}
