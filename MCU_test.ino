String cmd = "";

bool wob = false;
int bcMode = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "wob") {
      wob = true;
      bcMode = 0;
    }
    else if (cmd.startsWith("bc")) {
      int num = cmd.substring(2).toInt();

      if (num >= 1 && num <= 18) {
        bcMode = num;
        wob = false;
      }
    }
  }

  if (wob) {
    Serial.println(F(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Begin_wob"));
    printData();
    delay(1000);
  }

  if (bcMode > 0) {
    Serial.print(F(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>bc"));
    Serial.println(bcMode);
    printData();
    delay(1000);
  }
}

void printData() {
  Serial.println(F("RDCVA = cell_1->3.4466V cell_2->3.4345V cell_3->3.4476V"));
  Serial.println(F("RDCVB = cell_4->3.4340V cell_5->3.4408V"));
  Serial.println(F("RDCVC = cell_7->3.4443V cell_8->3.4359V cell_9->3.4377V"));
  Serial.println(F("RDCVD = cell_10->3.4354V cell_11->3.4438V"));
  Serial.println(F("RDCVE = cell_13->3.4336V cell_14->3.4474V cell_15->3.4345V"));
  Serial.println(F("RDCVF = cell_16->3.4426V cell_17->3.4481V cell_18->3.4378V"));
  Serial.println(F("GPIO1: 1.4605V  |  Temp->26.08C"));
  Serial.println(F("GPIO2: 1.4686V  |  Temp->25.84C"));
  Serial.println(F("GPIO3: 2.7317V  |  Temp->-19.08C"));
  Serial.println(F("GPIO4: 2.7700V  |  Temp->-21.74C"));
  Serial.println(F("GPIO5: 2.7666V  |  Temp->-21.49C"));
  Serial.println(F("Vref2 = 3.0036V"));
  Serial.println(F("GPIO6: 2.8117V  |  Temp->-25.06C"));
  Serial.println(F("GPIO7: 1.4988V  |  Temp->24.94C"));
  Serial.println(F("GPIO8: 1.4907V  |  Temp->25.18C"));
  Serial.println(F("GPIO9: 1.5167V  |  Temp->24.41C"));
  Serial.println(F("MCU1_APs->5.0400V (0xC4E0)    MCU2_APs->5.0483V (0xC533)"));
  Serial.println(F("MCU1_DPs->3.1421V (0x7ABD)    MCU2_DPs->3.1510V (0x7B16)"));
  Serial.println(F("Sum of All Cells->55.0500V"));
  Serial.println(F("Master Internal Die->24.763C"));
  Serial.println(F("Slave Internal Die->30.974C"));
  Serial.println(F("End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"));
}
