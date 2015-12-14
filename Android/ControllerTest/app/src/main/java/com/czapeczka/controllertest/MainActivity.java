package com.czapeczka.controllertest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.EditText;
import android.widget.Toast;

import com.czapeczka.controllertest.api.retrofit.PhotonApi;

import butterknife.Bind;
import butterknife.ButterKnife;
import butterknife.OnClick;
import rx.android.schedulers.AndroidSchedulers;
import rx.schedulers.Schedulers;

public class MainActivity extends AppCompatActivity {

    @Bind(R.id.et_temp)
    EditText etTemp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
    }

    @OnClick(R.id.btn_send)
    void onSendClicked() {
        int temp = Integer.valueOf(etTemp.getText().toString());
        PhotonApi.get().setTemperature(temp)
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(setTempResponse -> {
                    Toast.makeText(this, "Success", Toast.LENGTH_SHORT).show();
                }, throwable -> {
                    Log.e("tag", "error", throwable);
                    Toast.makeText(this, "Failed", Toast.LENGTH_SHORT).show();
                });
    }
}
