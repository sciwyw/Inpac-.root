

void test(){
    TString data_file = "data.root";

    // load the tree
    auto f = new TFile(data_file);
    auto domhit = (TTree*) f->Get("DomHit");
    // load data from trees to vectors
    vector<float> *domid=nullptr, *t=nullptr;
    vector<float> *hitx0=nullptr, *hity0=nullptr, *hitz0=nullptr;

    domhit->SetBranchAddress("DomId", &domid);
    domhit->SetBranchAddress("t0", &t);
    domhit->SetBranchAddress("x0", &hitx0);
    domhit->SetBranchAddress("y0", &hity0);
    domhit->SetBranchAddress("z0", &hitz0);

    // setup output
    ofstream out_file;
    out_file.open("domhit_data.txt",ios::out);
    out_file<<setw(10)<<"Event_Id"<<setw(10)<<"DomId"<<setw(10)<<"t0"<<setw(10)<<"x0"<<setw(10)<<"y0"<<setw(10)<<setw(10)<<"z0"<<endl;

    // obtain the value from ith entry
    // for(int ientry=0; ientry<domhit->GetEntries(); ientry++){
    for(int ientry=0; ientry<1; ientry++){
        domhit->GetEntry(ientry);
        for(int ihit=0; ihit<domid->size(); ihit++){
            out_file <<setw(10)<<ientry <<setw(10)<<(*domid)[ihit] <<setw(10)<<(*t)[ihit] <<setw(10)<<(*hitx0)[ihit] <<setw(10) <<(*hity0)[ihit] <<setw(10)<<(*hitz0)[ihit] <<endl;
        }
        
    }

    out_file.close();
}