volatile char k;
bool wob = false;
bool bc1 = false;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    k = Serial.read();

    if (k == 'c') {
      wob = true;
      bc1 = false;   // ปิดโหมดอื่น
    }     
    else if (k == 'd') {
      bc1 = true;
      wob = false;   // ปิดโหมดอื่น
    }
  }

  if (wob) {
    Serial.println(
">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Begin_wob\n"
"RDCVA = cell_1->3.4466V cell_2->3.4345V cell_3->3.4476V\n"
"RDCVB = cell_4->3.4340V cell_5->3.4408V\n"
"RDCVC = cell_7->3.4443V cell_8->3.4359V cell_9->3.4377V\n"
"RDCVD = cell_10->3.4354V cell_11->3.4438V\n"
"RDCVE = cell_13->3.4336V cell_14->3.4474V cell_15->3.4345V\n"
"RDCVF = cell_16->3.4426V cell_17->3.4481V cell_18->3.4378V\n"
"GPIO1: 1.4605V  |  Temp->26.08C\n"
"GPIO2: 1.4686V  |  Temp->25.84C\n"
"GPIO3: 2.7317V  |  Temp->-19.08C\n"
"GPIO4: 2.7700V  |  Temp->-21.74C\n"
"GPIO5: 2.7666V  |  Temp->-21.49C\n"
"Vref2 = 3.0036V\n"
"GPIO6: 2.8117V  |  Temp->-25.06C\n"
"GPIO7: 1.4988V  |  Temp->24.94C\n"
"GPIO8: 1.4907V  |  Temp->25.18C\n"
"GPIO9: 1.5167V  |  Temp->24.41C\n"
"MCU1_APs->5.0400V (0xC4E0)    MCU2_APs->5.0483V (0xC533)\n"
"MCU1_DPs->3.1421V (0x7ABD)    MCU2_DPs->3.1510V (0x7B16)\n"
"Sum of All Cells->55.0500V\n"
"Master Internal Die->24.763C\n"
"Slave Internal Die->30.974C\n"
"End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
    );
    delay(500);
  }

  if (bc1) {
    Serial.println(
">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BC_1\n"
"RDCVA = cell_1->3.4466V cell_2->3.4345V cell_3->3.4476V\n"
"RDCVB = cell_4->3.4340V cell_5->3.4408V\n"
"RDCVC = cell_7->3.4443V cell_8->3.4359V cell_9->3.4377V\n"
"RDCVD = cell_10->3.4354V cell_11->3.4438V\n"
"RDCVE = cell_13->3.4336V cell_14->3.4474V cell_15->3.4345V\n"
"RDCVF = cell_16->3.4426V cell_17->3.4481V cell_18->3.4378V\n"
"GPIO1: 1.4605V  |  Temp->26.08C\n"
"GPIO2: 1.4686V  |  Temp->25.84C\n"
"GPIO3: 2.7317V  |  Temp->-19.08C\n"
"GPIO4: 2.7700V  |  Temp->-21.74C\n"
"GPIO5: 2.7666V  |  Temp->-21.49C\n"
"Vref2 = 3.0036V\n"
"GPIO6: 2.8117V  |  Temp->-25.06C\n"
"GPIO7: 1.4988V  |  Temp->24.94C\n"
"GPIO8: 1.4907V  |  Temp->25.18C\n"
"GPIO9: 1.5167V  |  Temp->24.41C\n"
"MCU1_APs->5.0400V (0xC4E0)    MCU2_APs->5.0483V (0xC533)\n"
"MCU1_DPs->3.1421V (0x7ABD)    MCU2_DPs->3.1510V (0x7B16)\n"
"Sum of All Cells->55.0500V\n"
"Master Internal Die->24.763C\n"
"Slave Internal Die->30.974C\n"
"End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
    );
    delay(500);
  }
}
