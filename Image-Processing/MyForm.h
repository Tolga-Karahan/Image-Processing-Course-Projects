#pragma once
#include <atlstr.h>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include "imge_bmp.h"
#include "MyForm2.h"
#include "Segmentation.h"
#include "MyVector.h"
#include "Clustering.h"
#include "Filter.h"
using namespace std;

namespace ImageProcessing {

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		BYTE* Buffer;
		BYTE* Raw_Intensity;
		int Width, Height;
		long Size, new_size;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramOperationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramEqualizationToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::ToolStripMenuItem^  segmentationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  binarySegmentationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  euclideanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mahalanobisToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clusteringToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  euclideanToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  mahalanobisToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  morphologicalOperationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  erosionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closingToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  labelingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kThresholdingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  edgeDetectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cannyEdgeToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramOperationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramEqualizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->segmentationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binarySegmentationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->euclideanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mahalanobisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kThresholdingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clusteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->euclideanToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mahalanobisToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->morphologicalOperationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->edgeDetectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cannyEdgeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->openToolStripMenuItem,
					this->histogramOperationsToolStripMenuItem, this->segmentationToolStripMenuItem, this->clusteringToolStripMenuItem, this->morphologicalOperationsToolStripMenuItem,
					this->labelingToolStripMenuItem, this->edgeDetectionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1035, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// histogramOperationsToolStripMenuItem
			// 
			this->histogramOperationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->histogramToolStripMenuItem,
					this->histogramEqualizationToolStripMenuItem
			});
			this->histogramOperationsToolStripMenuItem->Name = L"histogramOperationsToolStripMenuItem";
			this->histogramOperationsToolStripMenuItem->Size = System::Drawing::Size(136, 20);
			this->histogramOperationsToolStripMenuItem->Text = L"Histogram Operations";
			// 
			// histogramToolStripMenuItem
			// 
			this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
			this->histogramToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->histogramToolStripMenuItem->Text = L"Histogram";
			this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramToolStripMenuItem_Click);
			// 
			// histogramEqualizationToolStripMenuItem
			// 
			this->histogramEqualizationToolStripMenuItem->Name = L"histogramEqualizationToolStripMenuItem";
			this->histogramEqualizationToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->histogramEqualizationToolStripMenuItem->Text = L"Histogram Equalization";
			this->histogramEqualizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramEqualizationToolStripMenuItem_Click);
			// 
			// segmentationToolStripMenuItem
			// 
			this->segmentationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binarySegmentationToolStripMenuItem,
					this->kThresholdingToolStripMenuItem
			});
			this->segmentationToolStripMenuItem->Name = L"segmentationToolStripMenuItem";
			this->segmentationToolStripMenuItem->Size = System::Drawing::Size(93, 20);
			this->segmentationToolStripMenuItem->Text = L"Segmentation";
			// 
			// binarySegmentationToolStripMenuItem
			// 
			this->binarySegmentationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->euclideanToolStripMenuItem,
					this->mahalanobisToolStripMenuItem
			});
			this->binarySegmentationToolStripMenuItem->Name = L"binarySegmentationToolStripMenuItem";
			this->binarySegmentationToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->binarySegmentationToolStripMenuItem->Text = L"Binary Segmentation";
			// 
			// euclideanToolStripMenuItem
			// 
			this->euclideanToolStripMenuItem->Name = L"euclideanToolStripMenuItem";
			this->euclideanToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->euclideanToolStripMenuItem->Text = L"Euclidean";
			this->euclideanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::euclideanToolStripMenuItem_Click);
			// 
			// mahalanobisToolStripMenuItem
			// 
			this->mahalanobisToolStripMenuItem->Name = L"mahalanobisToolStripMenuItem";
			this->mahalanobisToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->mahalanobisToolStripMenuItem->Text = L"Mahalanobis";
			this->mahalanobisToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::mahalanobisToolStripMenuItem_Click);
			// 
			// kThresholdingToolStripMenuItem
			// 
			this->kThresholdingToolStripMenuItem->Name = L"kThresholdingToolStripMenuItem";
			this->kThresholdingToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->kThresholdingToolStripMenuItem->Text = L"K - Thresholding";
			this->kThresholdingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::kThresholdingToolStripMenuItem_Click);
			// 
			// clusteringToolStripMenuItem
			// 
			this->clusteringToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->euclideanToolStripMenuItem1,
					this->mahalanobisToolStripMenuItem1
			});
			this->clusteringToolStripMenuItem->Name = L"clusteringToolStripMenuItem";
			this->clusteringToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->clusteringToolStripMenuItem->Text = L"Clustering";
			// 
			// euclideanToolStripMenuItem1
			// 
			this->euclideanToolStripMenuItem1->Name = L"euclideanToolStripMenuItem1";
			this->euclideanToolStripMenuItem1->Size = System::Drawing::Size(142, 22);
			this->euclideanToolStripMenuItem1->Text = L"Euclidean";
			this->euclideanToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::euclideanToolStripMenuItem1_Click);
			// 
			// mahalanobisToolStripMenuItem1
			// 
			this->mahalanobisToolStripMenuItem1->Name = L"mahalanobisToolStripMenuItem1";
			this->mahalanobisToolStripMenuItem1->Size = System::Drawing::Size(142, 22);
			this->mahalanobisToolStripMenuItem1->Text = L"Mahalanobis";
			// 
			// morphologicalOperationsToolStripMenuItem
			// 
			this->morphologicalOperationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->dilationToolStripMenuItem,
					this->erosionToolStripMenuItem, this->openingToolStripMenuItem, this->closingToolStripMenuItem
			});
			this->morphologicalOperationsToolStripMenuItem->Name = L"morphologicalOperationsToolStripMenuItem";
			this->morphologicalOperationsToolStripMenuItem->Size = System::Drawing::Size(158, 20);
			this->morphologicalOperationsToolStripMenuItem->Text = L"Morphological Operations";
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->dilationToolStripMenuItem->Text = L"Dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dilationToolStripMenuItem_Click);
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->erosionToolStripMenuItem->Text = L"Erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::erosionToolStripMenuItem_Click);
			// 
			// openingToolStripMenuItem
			// 
			this->openingToolStripMenuItem->Name = L"openingToolStripMenuItem";
			this->openingToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->openingToolStripMenuItem->Text = L"Opening";
			this->openingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openingToolStripMenuItem_Click);
			// 
			// closingToolStripMenuItem
			// 
			this->closingToolStripMenuItem->Name = L"closingToolStripMenuItem";
			this->closingToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->closingToolStripMenuItem->Text = L"Closing";
			this->closingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closingToolStripMenuItem_Click);
			// 
			// labelingToolStripMenuItem
			// 
			this->labelingToolStripMenuItem->Name = L"labelingToolStripMenuItem";
			this->labelingToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->labelingToolStripMenuItem->Text = L"Labeling";
			this->labelingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::labelingToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 473);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(532, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(503, 473);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(532, 27);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(503, 478);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// edgeDetectionToolStripMenuItem
			// 
			this->edgeDetectionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->cannyEdgeToolStripMenuItem });
			this->edgeDetectionToolStripMenuItem->Name = L"edgeDetectionToolStripMenuItem";
			this->edgeDetectionToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->edgeDetectionToolStripMenuItem->Text = L"Edge Detection";
			// 
			// cannyEdgeToolStripMenuItem
			// 
			this->cannyEdgeToolStripMenuItem->Name = L"cannyEdgeToolStripMenuItem";
			this->cannyEdgeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->cannyEdgeToolStripMenuItem->Text = L"Canny Edge";
			this->cannyEdgeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cannyEdgeToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1035, 505);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Image Processing";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	// Renkli resmi ekrana bas
	public: void displayRGB(BYTE* img)
	{
		this->chart1->Visible = false;
		unsigned int row, column;
		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;
		Color c;
		for (row = 0; row < Height; row++)
		{
			for (column = 0; column < Width; column++)
			{
				int index = (row * Width + column);
				c = Color::FromArgb(img[index], img[index + 1], img[index + 2]);
				surface->SetPixel(column, row, c);
			}
		}
	}

	// Gri resmi ekrana bas
	public: void displayGray(BYTE* img)
	{
		this->chart1->Visible = false;
		unsigned int row, column;
		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;
		Color c;
		for (row = 0; row < Height; row++)
		{
			for (column = 0; column < Width; column++)
			{
				int index = (row * Width + column);
				c = Color::FromArgb(img[index], img[index], img[index]);
				surface->SetPixel(column, row, c);
			}
		}
	}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		LPCTSTR input;
		CString str;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			Buffer = LoadBMP(Width, Height, Size, input);

			pictureBox1->Width = Width;
			pictureBox1->Height = Height;
			pictureBox1->ImageLocation = openFileDialog1->FileName;
			Raw_Intensity = NULL;
		}
		else MessageBox::Show("Couldn't open the file.");

		String^ response = Microsoft::VisualBasic::Interaction::InputBox("Is converting to intensity required? Y/N?", "Convert to Intensity", "", 500, 300);
		
		if (response->Empty)
		{
			// do nothing
		}
		else if (Convert::ToChar(response) == 'Y')
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			MessageBox::Show("Image is converted to intensity");
		}
	}
	
	private: System::Void histogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		BYTE histogram[256] = { 0 };

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				histogram[Raw_Intensity[row * Width + column]]++;
			}
		}

		this->chart1->Series->Clear();
		System::Windows::Forms::DataVisualization::Charting::Series^  series1 =
			(gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		this->chart1->Series->Add(series1);

		for (int i = 0; i < 256; i++)
			series1->Points->AddXY(i, histogram[i]);
		this->chart1->Visible = true;
	}
	private: System::Void histogramEqualizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		int histogram[256] = { 0 };
		int equalizedHistogram[256] = { 0 };
		BYTE lookUpTable[256];
		int runningSum = 0;
		int numberOfPixels = Width * Height;


		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				histogram[Raw_Intensity[row * Width + column]]++;
			}
		}

		for (int i = 0; i < 256; i++)
		{
			runningSum += histogram[i];
			BYTE newPixelValue = round(((runningSum * 1.0 / numberOfPixels) * 255));
			equalizedHistogram[newPixelValue] += histogram[i];
			lookUpTable[i] = newPixelValue;
		}

		MyForm2^ histogramForm = gcnew MyForm2;
		histogramForm->equalizeHistogram(histogram, equalizedHistogram);
		histogramForm->Show();

		

		this->chart1->Visible = false;

		pictureBox2->Width = Width;
		pictureBox2->Height = Height;

		unsigned int row, column;
		Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
		pictureBox2->Image = surface;
		Color c;
		for (row = 0; row < Height; row++)
		{
			for (column = 0; column < Width; column++)
			{
				Raw_Intensity[row * Width + column] = lookUpTable[Raw_Intensity[row * Width + column]];
				c = Color::FromArgb(Raw_Intensity[row*Width + column], Raw_Intensity[row*Width + column], Raw_Intensity[row*Width + column]);
				surface->SetPixel(column, row, c);
			}
		}
	}

	private: System::Void euclideanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		Segmentation segmentation(Raw_Intensity, Width, Height, true);
		BYTE* buffer = segmentation.doSegmentation();
		
		displayGray(buffer);
		Raw_Intensity = NULL;
	}
	private: System::Void mahalanobisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		Segmentation segmentation(Raw_Intensity, Width, Height, false);
		BYTE* buffer = segmentation.doSegmentation();

		displayGray(buffer);
		Raw_Intensity = NULL;
	}
	
	private: System::Void euclideanToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

		Clustering cluster(Buffer, Width, Height);
		cluster.makeClustering();
		BYTE* buffer = cluster.getIMG();

		this->chart1->Visible = false;
		unsigned int row, column;
		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;
		Color c;
		for (row = 0; row < Height; row++)
		{
			for (column = 0; column < Width; column++)
			{
				int index = (row * Width + column) * 3;
				c = Color::FromArgb(buffer[index + 2], buffer[index + 1], buffer[index]);
				surface->SetPixel(column , Height - row - 1, c);
			}
		}
	}
	private: System::Void dilationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
		// Filtreleme sonucunun tutulacaðý buffer
		BYTE* buffer;
		// Mask matrisi
		BYTE mask[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		// Resim zaten açýlmýþsa tekrar açma
		if (Raw_Intensity == NULL)
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			Segmentation seg(Raw_Intensity, Width, Height, true);
			Raw_Intensity = seg.doSegmentation();
		}
		
		Filter filter(Raw_Intensity, Width, Height);
		Raw_Intensity = filter.dilation(mask);

		displayGray(Raw_Intensity);
	}

	private: System::Void erosionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		// Mask matrisi
		BYTE mask[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Resim zaten açýlmýþsa tekrar açma
		if (Raw_Intensity == NULL)
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			Segmentation seg(Raw_Intensity, Width, Height, true);
			Raw_Intensity = seg.doSegmentation();
		}
		Filter filter(Raw_Intensity, Width, Height);
		Raw_Intensity = filter.erosion(mask);
		
		displayGray(Raw_Intensity);
		
	}
	private: System::Void openingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		// Mask matrisi
		BYTE mask[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Resim zaten açýlmýþsa tekrar açma
		if (Raw_Intensity == NULL)
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			Segmentation seg(Raw_Intensity, Width, Height, true);
			Raw_Intensity = seg.doSegmentation();
		}

		Filter filter(Raw_Intensity, Width, Height);
		Raw_Intensity = filter.erosion(mask);
		filter.updateIMG(Raw_Intensity);
		Raw_Intensity = filter.dilation(mask);

		displayGray(Raw_Intensity);
	}
	private: System::Void closingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		// Mask matrisi
		BYTE mask[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Resim zaten açýlmýþsa tekrar açma
		if (Raw_Intensity == NULL)
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			Segmentation seg(Raw_Intensity, Width, Height, true);
			Raw_Intensity = seg.doSegmentation();
		}

		Filter filter(Raw_Intensity, Width, Height);
		Raw_Intensity = filter.dilation(mask);
		filter.updateIMG(Raw_Intensity);
		Raw_Intensity = filter.erosion(mask);

		displayGray(Raw_Intensity);
	}
	
	private: System::Void labelingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		// etiket numarasý
		int label = 1;

		// etiketlerin tutulacaðý dizi
		BYTE* labels = new BYTE[Width * Height];

		// etiketleri tutan diziyi sýfýrla
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Width; j++)
				labels[i * Width + j] = 0;

		// Resmi aç ve ikili görüntüye çevir
		if (Raw_Intensity == NULL)
		{
			Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
			Segmentation seg(Raw_Intensity, Width, Height, true);
			Raw_Intensity = seg.doSegmentation();
		}

		for (int row = 1; row < Height - 1; row++)
		{
			for (int column = 1; column < Width - 1; column++)
			{
				int index = (row * Width + column);

				// piksel içeriði beyazsa sonraki piksele geç
				if (Raw_Intensity[index] == 255)
					continue;
				
				// üst ve alt komþularý al
				BYTE neighborUp = labels[index - Width];
				BYTE neighborLeft = labels[index - 1];

				if (neighborUp == 0 && neighborLeft == 0)
				{
					labels[index] = label++;
				}
				else
				{
					if (neighborUp == 0)
						labels[index] = neighborLeft;
					else if (neighborLeft == 0)
						labels[index] = neighborUp;
					else
					{
						if (neighborUp < neighborLeft)
						{
							labels[index] = neighborUp;
							// küçük olan etiket ile deðiþtir
							update(labels, neighborLeft, neighborUp);
							// etiket sayýsýný azalt
							label--;
						}
						else if(neighborLeft < neighborUp)
						{
							labels[index] = neighborLeft;
							// küçük olan etiket ile deðiþtir
							update(labels, neighborUp, neighborLeft);
							// etiket sayýsýný azalt
							label--;
						}
						else
						{
							labels[index] = neighborUp;
						}
					}
				}
			}
		}


		MessageBox::Show(Convert::ToString(label - 1) + " objects are found.");
	}

	public: void update(BYTE* labels, BYTE toBeReplaced, BYTE replaceWith)
	{
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				int index = (row * Width + column);

				// etiketi deðiþtir
				if (labels[index] == toBeReplaced)
					labels[index] = replaceWith;
			}
		}
	}
	private: System::Void kThresholdingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);
		String^ input = Microsoft::VisualBasic::Interaction::InputBox("Enter the k value", "K - Means", "", 500, 300);
		Segmentation seg(Raw_Intensity, Width, Height, true);
		BYTE* buffer = seg.KThresholding(Convert::ToInt32(input));
		displayGray(buffer);
	}
	private: System::Void cannyEdgeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		
		BYTE* magnitude = new BYTE[Width*Height];
		double* orientation = new double[Width*Height];
		BYTE* edgeImage = new BYTE[Width*Height];

		// Gri resme cevir
		Raw_Intensity = ConvertBMPToIntensity(Buffer, Width, Height);

		// filtreleme islemleri icin nesne olustur
		Filter filtering(Raw_Intensity, Width, Height);
		
		// bulaniklastir
		double gaussian[] = { 0.0625, 0.125, 0.0625, 0.0125, 0.25, 0.0125, 0.0625, 0.0125, 0.0625 };
		filtering.filtering(gaussian);
		
		// dikey eksende gradienti hesapla
		BYTE verticalSobel[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
		BYTE* verticalGradient = filtering.filtering(verticalSobel);

		// yatay eksende gradienti hesapla
		BYTE horizontalSobel[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
		BYTE* horizontalGradient = filtering.filtering(horizontalSobel);

		// genlik ve yon bilgisini hesapla
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				int index = row * Width + column;
				magnitude[index] = sqrt(pow(verticalGradient[index], 2) + pow(horizontalGradient[index], 2));
				orientation[index] = atan(1.0 * verticalGradient[index] / horizontalGradient[index]) * 180 / M_PI;
			}
		}

		// non-maximum supression
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				int index = row * Width + column;
				double angle = orientation[index];

				if (angle >= 22.5 && angle <= 67.5)
				{
					// merkez pikseli sol ust ve sag alt komsu pikseller ile karsilastir
					int topLeftPixel = Raw_Intensity[index - Width - 1];
					int bottomRightPixel = Raw_Intensity[index + Width + 1];
					int centralPixel = Raw_Intensity[index];

					// merkez piksel komsulardan buyukse kenar olarak isaretlenir
					// komsulardan kucukse yok edilir(supression)
					if (centralPixel > topLeftPixel && centralPixel > bottomRightPixel)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}		
				}

				else if (angle >= 67.5 && angle <= 112.5)
				{
					// merkez pikseli ust ve alt komsu pikseller ile karsilastir
					int abovePixel = Raw_Intensity[index - Width];
					int belowPixel = Raw_Intensity[index + Width];
					int centralPixel = Raw_Intensity[index];

					// merkez piksel komsulardan buyukse kenar olarak isaretlenir
					// komsulardan kucukse yok edilir(supression)
					if (centralPixel > abovePixel && centralPixel > belowPixel)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}

				else if (angle >= 112.5 && angle <= 157.5)
				{
					// merkez pikseli sag ust ve sol alt komsu pikseller ile karsilastir
					int topRightPixel = Raw_Intensity[index - Width + 1];
					int bottomLeftPixel = Raw_Intensity[index + Width - 1];
					int centralPixel = Raw_Intensity[index];

					// merkez piksel komsulardan buyukse kenar olarak isaretlenir
					// komsulardan kucukse yok edilir(supression)
					if (centralPixel > topRightPixel && centralPixel > bottomLeftPixel)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}

				// 0 - 22.5 ve 157.5 - 180 derece arasi degerlendirilir
				else
				{
					// merkez pikseli sol ve sag komsu pikseller ile karsilastir
					int leftPixel = Raw_Intensity[index - 1];
					int rightPixel = Raw_Intensity[index + 1];
					int centralPixel = Raw_Intensity[index];

					// merkez piksel komsulardan buyukse kenar olarak isaretlenir
					// komsulardan kucukse yok edilir(supression)
					if (centralPixel > leftPixel && centralPixel > rightPixel)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}
				
			}
		}

		// hysteresis thresholding 
		// bu sefer gradient yonune degil kenar yonundeki piksellere bakariz
		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				int index = row * Width + column;
				// kenar degilse sonraki piksel ile devam et
				if (Raw_Intensity[index] == 255) continue;
				double angle = orientation[index];

				if (angle >= 22.5 && angle <= 67.5)
				{
					int topRightIndex = index - Width + 1;
					int bottomLeftIndex = index + Width - 1;
					
					// komsu pikseller merkez pikselle ayni gradient acisina mi sahip?
					bool isOrientationEquals = orientation[index] == orientation[topRightIndex] ||
						orientation[index] == orientation[bottomLeftIndex];

					// komsu pikseller maksimum mu?
					bool wasntBeSupressed = edgeImage[topRightIndex] == 0 || edgeImage[bottomLeftIndex] == 0;

					if (isOrientationEquals && wasntBeSupressed)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}				
				}

				else if (angle >= 67.5 && angle <= 112.5)
				{
					int leftIndex = index - 1;
					int rightIndex = index + 1;

					// komsu pikseller merkez pikselle ayni gradient acisina mi sahip?
					bool isOrientationEquals = orientation[index] == orientation[leftIndex] ||
						orientation[index] == orientation[rightIndex];

					// komsu pikseller maksimum mu?
					bool wasntBeSupressed = edgeImage[leftIndex] == 0 || edgeImage[rightIndex] == 0;

					if (isOrientationEquals && wasntBeSupressed)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}

				else if (angle >= 112.5 && angle <= 157.5)
				{
					int topLeftIndex = index - 1;
					int bottomRightIndex = index + 1;

					// komsu pikseller merkez pikselle ayni gradient acisina mi sahip?
					bool isOrientationEquals = orientation[index] == orientation[topLeftIndex] ||
						orientation[index] == orientation[bottomRightIndex];

					// komsu pikseller maksimum mu?
					bool wasntBeSupressed = edgeImage[topLeftIndex] == 0 || edgeImage[bottomRightIndex] == 0;

					if (isOrientationEquals && wasntBeSupressed)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}

				else
				{
					int aboveIndex = index - 1;
					int belowIndex = index + 1;

					// komsu pikseller merkez pikselle ayni gradient acisina mi sahip?
					bool isOrientationEquals = orientation[index] == orientation[aboveIndex] ||
						orientation[index] == orientation[belowIndex];

					// komsu pikseller maksimum mu?
					bool wasntBeSupressed = edgeImage[aboveIndex] == 0 || edgeImage[belowIndex] == 0;

					if (isOrientationEquals && wasntBeSupressed)
					{
						edgeImage[index] = 0;
					}
					else
					{
						edgeImage[index] = 255;
					}
				}
			}
		}
		
	}
};
}
