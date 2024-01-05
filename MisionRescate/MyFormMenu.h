#pragma once
#include "MyForm.h"
#include "Instrucciones.h"
#include "Creditos.h"
#include "MyForm1.h"
namespace MisionRescate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyFormMenu
	/// </summary>
	public ref class MyFormMenu : public System::Windows::Forms::Form
	{
	public:
		int agregar;
	private: System::Windows::Forms::Label^ Sonido;
	public:

	public:
		SoundPlayer^ SMenu = gcnew SoundPlayer("sonido/smenu.wav");
		MyFormMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			agregar = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyFormMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ MusicaActivado;
	private: System::Windows::Forms::RadioButton^ DesacMusica;








	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyFormMenu::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MusicaActivado = (gcnew System::Windows::Forms::RadioButton());
			this->DesacMusica = (gcnew System::Windows::Forms::RadioButton());
			this->Sonido = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->FlatAppearance->BorderSize = 5;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(272, 212);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(256, 114);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Iniciar Juego";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyFormMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->FlatAppearance->BorderSize = 5;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(272, 401);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(256, 54);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Creditos";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyFormMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->FlatAppearance->BorderSize = 5;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold));
			this->button3->Location = System::Drawing::Point(272, 337);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(256, 54);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Instrucciones";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyFormMenu::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(780, 692);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyFormMenu::pictureBox1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(252, 154);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 42);
			this->label1->TabIndex = 3;
			this->label1->Text = L"MisionRescate";
			this->label1->Click += gcnew System::EventHandler(this, &MyFormMenu::label1_Click);
			// 
			// MusicaActivado
			// 
			this->MusicaActivado->AutoSize = true;
			this->MusicaActivado->BackColor = System::Drawing::Color::Transparent;
			this->MusicaActivado->Location = System::Drawing::Point(559, 639);
			this->MusicaActivado->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MusicaActivado->Name = L"MusicaActivado";
			this->MusicaActivado->Size = System::Drawing::Size(81, 20);
			this->MusicaActivado->TabIndex = 6;
			this->MusicaActivado->TabStop = true;
			this->MusicaActivado->Text = L"Activado";
			this->MusicaActivado->UseVisualStyleBackColor = false;
			this->MusicaActivado->CheckedChanged += gcnew System::EventHandler(this, &MyFormMenu::radioButton1_CheckedChanged);
			// 
			// DesacMusica
			// 
			this->DesacMusica->AutoSize = true;
			this->DesacMusica->Location = System::Drawing::Point(648, 639);
			this->DesacMusica->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->DesacMusica->Name = L"DesacMusica";
			this->DesacMusica->Size = System::Drawing::Size(105, 20);
			this->DesacMusica->TabIndex = 7;
			this->DesacMusica->TabStop = true;
			this->DesacMusica->Text = L"Desactivado";
			this->DesacMusica->UseVisualStyleBackColor = true;
			this->DesacMusica->CheckedChanged += gcnew System::EventHandler(this, &MyFormMenu::radioButton1_CheckedChanged_1);
			// 
			// Sonido
			// 
			this->Sonido->AutoSize = true;
			this->Sonido->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sonido->Location = System::Drawing::Point(601, 594);
			this->Sonido->Name = L"Sonido";
			this->Sonido->Size = System::Drawing::Size(96, 29);
			this->Sonido->TabIndex = 8;
			this->Sonido->Text = L"Sonido";
			this->Sonido->Click += gcnew System::EventHandler(this, &MyFormMenu::label2_Click);
			// 
			// MyFormMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(776, 681);
			this->Controls->Add(this->Sonido);
			this->Controls->Add(this->DesacMusica);
			this->Controls->Add(this->MusicaActivado);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximumSize = System::Drawing::Size(794, 728);
			this->MinimumSize = System::Drawing::Size(794, 728);
			this->Name = L"MyFormMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyFormMenu";
			this->Load += gcnew System::EventHandler(this, &MyFormMenu::MyFormMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) 
{
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Instrucciones^ frn = gcnew Instrucciones();
	this->Visible = false;
	frn->ShowDialog();
	this->Visible = true;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MyForm1^ frn = gcnew MyForm1();
	this->Visible = false;
	frn->ShowDialog();
	this->Visible = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Creditos^ frn = gcnew Creditos();
	this->Visible = false;
	frn->ShowDialog();
	this->Visible = true;
}
private: System::Void MyFormMenu_Load(System::Object^ sender, System::EventArgs^ e) 
{
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) 
{
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	SMenu->PlayLooping();
}
private: System::Void radioButton1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) 
{
	SMenu->Stop();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
